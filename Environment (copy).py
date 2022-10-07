import numpy as np
from scipy import stats
import subprocess
import networkx as nx

from helper import pretty, softmax
from Traffic import Traffic


OMTRAFFIC = 'Traffic.txt'
OMBALANCING = 'Balancing.txt'
OMROUTING = 'Routing.txt'
OMDELAY = 'Delay.csv'
OMLOSS = 'lossPacket.csv'

TRAFFICLOG = 'TrafficLog.csv'
BALANCINGLOG = 'BalancingLog.csv'
REWARDLOG = 'rewardLog.csv'
WHOLELOG = 'Log.csv'
OMLOG = 'omnetLog.csv'


# FROM MATRIX
def matrix_to_rl(matrix):
    return matrix[(matrix!=-1)]

matrix_to_log_v = matrix_to_rl

def matrix_to_omnet_v(matrix):
    return matrix.flatten()

def vector_to_file(vector, file_name, action):
    string = ','.join(pretty(_) for _ in vector)
    with open(file_name, action) as file:
        return file.write(string + '\n')


# FROM FILE
def file_to_csv(file_name):
    # reads file, outputs csv
    with open(file_name, 'r') as file:
        return file.readline().strip().strip(',')

def csv_to_matrix(string, nodes_num):
    # reads text, outputs matrix
    v = np.asarray(tuple(float(x) for x in string.split(',')[:nodes_num**2]))
    M = np.split(v, nodes_num)
    return np.vstack(M)

def csv_to_lost(string):
    return float(string.split(',')[-1])


# FROM RL
def rl_to_matrix(vector, nodes_num):
    M = np.split(vector, nodes_num)
    for _ in range(nodes_num):
        M[_] = np.insert(M[_], _, -1)
    return np.vstack(M)


# TO RL
def rl_state(env):
    if env.STATUM == 'RT':
        return np.concatenate((matrix_to_rl(env.env_B), matrix_to_rl(env.env_T)))
    elif env.STATUM == 'T':
        return matrix_to_rl(env.env_T)

def rl_reward(env):

    m = env.env_D
    mask = (m != np.Inf) & (m != -1)
    delay = m[mask]

    if env.PRAEMIUM == 'AVG':
        reward = -np.mean(matrix_to_rl(delay))
    elif env.PRAEMIUM == 'MAX':
        reward = -np.max(matrix_to_rl(delay))
    elif env.PRAEMIUM == 'AXM':
        reward = -(np.mean(matrix_to_rl(delay)) + np.max(matrix_to_rl(delay)))/2
    elif env.PRAEMIUM == 'GEO':
        reward = -stats.gmean(matrix_to_rl(delay))
    elif env.PRAEMIUM == 'LOST':
        reward = -env.env_L
    return reward


# WRAPPER ITSELF
def omnet_wrapper(env):
    simexe = 'SDN_simulator/src/SDN_simulator'
    simfolder = 'SDN_simulator/simulations:SDN_simulator/src'
    simini = 'SDN_simulator/simulations/omnetpp.ini'
    try:
        # omnet_output = subprocess.check_output([simexe, '-n', simfolder, simini, env.folder + 'folder.ini']).decode()
        omnet_output = subprocess.check_output([simexe, '-u', 'Cmdenv', '-n', simfolder, simini, env.folder + 'folder.ini']).decode()
    except Exception as e:
        omnet_output = e.stdout.decode()
        print(omnet_output)

    if 'Error' in omnet_output:
        omnet_output = omnet_output.replace(',', '')
        o_u_l = [_.strip() for _ in omnet_output.split('\n') if _ is not '']
        omnet_output = ','.join(o_u_l[4:])
    else:
        omnet_output = 'ok'

    vector_to_file([omnet_output], env.folder + OMLOG, 'a')


# label environment
class OmnetLinkweightEnv():
    def __init__(self, DDPG_config, folder):
        self.ENV = 'label'
        self.ROUTING = 'Linkweight'

        self.folder = folder

        self.ACTIVE_NODES = DDPG_config.ACTIVE_NODES

        self.ACTUM = DDPG_config.ACTUM

        topology = 'network_info/GEANT/NetworkAll.matrix'
        ports = 'network_info/GEANT/NetworkAll.ports'

        self.graph = nx.Graph(np.loadtxt(topology, dtype=int))
        if self.ACTIVE_NODES != self.graph.number_of_nodes():
            return False
        self.ports = np.loadtxt(ports, dtype=int)

        self.a_dim = self.graph.number_of_edges()
        self.s_dim = self.ACTIVE_NODES**2 - self.ACTIVE_NODES    # traffic minus diagonal

        self.STATUM = DDPG_config.STATUM
        if self.STATUM == 'RT':
            self.s_dim *= 2    # traffic + routing table minus diagonals

        self.PRAEMIUM = DDPG_config.PRAEMIUM

        capacity = self.ACTIVE_NODES * (self.ACTIVE_NODES -1)

        self.TRAFFIC = DDPG_config.TRAFFIC
        self.tgen = Traffic(self.ACTIVE_NODES, self.TRAFFIC, capacity)

        self.env_T = np.full([self.ACTIVE_NODES]*2, -1.0, dtype=float)  # traffic
        self.env_W = np.full([self.a_dim], -1.0, dtype=float)           # weights
        self.env_R = np.full([self.ACTIVE_NODES]*2, -1.0, dtype=int)    # routing
        self.env_Rn = np.full([self.ACTIVE_NODES]*2, -1.0, dtype=int)   # routing (nodes)
        self.env_D = np.full([self.ACTIVE_NODES]*2, -1.0, dtype=float)  # delay
        self.env_L = -1.0  # lost packets

        self.counter = 0

    def upd_env_T(self, matrix):
        self.env_T = np.asarray(matrix)
        np.fill_diagonal(self.env_T, -1)

    def upd_env_W(self, vector):
        self.env_W = np.asarray(softmax(vector))

    def upd_env_R(self):
        weights = {}

        for e, w in zip(self.graph.edges(), self.env_W):
            weights[e] = w

        nx.set_edge_attributes(self.graph, 'weight', weights)

        routing_nodes = np.full([self.ACTIVE_NODES]*2, -1.0, dtype=int)
        routing_ports = np.full([self.ACTIVE_NODES]*2, -1.0, dtype=int)

        all_shortest = nx.all_pairs_dijkstra_path(self.graph)

        for s in range(self.ACTIVE_NODES):
            for d in range(self.ACTIVE_NODES):
                if s != d:
                    next = all_shortest[s][d][1]
                    port = self.ports[s][next]
                    routing_nodes[s][d] = next
                    routing_ports[s][d] = port
                else:
                    routing_nodes[s][d] = -1
                    routing_ports[s][d] = -1

        self.env_R = np.asarray(routing_ports)
        self.env_Rn = np.asarray(routing_nodes)

    def upd_env_D(self):
        self.env_D = np.loadtxt(self.folder + OMDELAY, delimiter=',')

    def upd_env_L(self):
        self.env_L = np.loadtxt(self.folder + OMLOSS).sum()

    def logheader(self, easy=False):
        nice_matrix = np.chararray([self.ACTIVE_NODES]*2, itemsize=20)
        for i in range(self.ACTIVE_NODES):
            for j in range(self.ACTIVE_NODES):
                nice_matrix[i][j] = str(i) + '-' + str(j)
        np.fill_diagonal(nice_matrix, '_')
        nice_list = list(nice_matrix[(nice_matrix!=b'_')])
        th = ['t' + _.decode('ascii') for _ in nice_list]
        rh = ['r' + _.decode('ascii') for _ in nice_list]
        dh = ['d' + _.decode('ascii') for _ in nice_list]
        ah = ['a' + str(_[0]) + '-' + str(_[1]) for _ in self.graph.edges()]
        header = ['counter'] + th + rh + dh + ['lost'] + ah + ['reward']
        if easy:
            header = ['counter', 'lost', 'AVG', 'MAX', 'AXM', 'GEO']
        vector_to_file(header, self.folder + WHOLELOG, 'w')

    def reset(self, easy=False):
        if self.counter != 0:
            return None

        self.logheader(easy)

        # routing
        self.upd_env_W(np.full([self.a_dim], 0.50, dtype=float))
        self.upd_env_R()
        if self.ACTUM == 'DELTA':
            vector_to_file(matrix_to_omnet_v(self.env_R), self.folder + OMROUTING, 'w')
            # VERIFY FILE POSITION AND FORMAT (separator, matrix/vector) np.savetxt("tmp.txt", routing, fmt="%d")

        # traffic
        self.upd_env_T(self.tgen.generate())

        vector_to_file(matrix_to_omnet_v(self.env_T), self.folder + OMTRAFFIC, 'w')

        return rl_state(self)

    def step(self, action):
        self.counter += 1

        self.upd_env_W(action)
        self.upd_env_R()

        # write to file input for Omnet: Routing
        vector_to_file(matrix_to_omnet_v(self.env_R), self.folder + OMROUTING, 'w')

        # execute omnet
        omnet_wrapper(self)

        # read Omnet's output: Delay and Lost
        self.upd_env_D()
        self.upd_env_L()

        reward = rl_reward(self)

        # log everything to file
        vector_to_file([-reward], self.folder + REWARDLOG, 'a')
        cur_state = rl_state(self)
        log = np.concatenate(([self.counter], matrix_to_log_v(self.env_T), matrix_to_log_v(self.env_Rn), matrix_to_log_v(self.env_D), [self.env_L], matrix_to_log_v(self.env_W), [-reward]))
        vector_to_file(log, self.folder + WHOLELOG, 'a')

        # generate traffic for next iteration
        self.upd_env_T(self.tgen.generate())
        
        # write to file input for Omnet: Traffic, or do nothing if static
        if self.TRAFFIC.split(':')[0] not in ('STAT', 'STATEQ', 'FILE'):
            vector_to_file(matrix_to_omnet_v(self.env_T), self.folder + OMTRAFFIC, 'w')

        new_state = rl_state(self)
        # return new status and reward
        return new_state, reward

    def end(self):
        return