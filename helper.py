import time
import os
import json
import argparse
from collections import OrderedDict
import numpy as np


def setup_run(DDPG_config):
    folder = DDPG_config.EXPERIMENT
    epoch = 't%.6f/' % time.time()
    folder += epoch.replace('.', '')
    os.makedirs(folder, exist_ok=True)

    with open(folder + 'folder.ini', 'w') as ifile:
        ifile.write('[General]\n')
        ifile.write('**.folderName = "' + folder + '"\n')

    DDPG_config

    # if DDPG_config['TRAFFIC'].startswith('STAT:'):
    #     with open(folder + 'Traffic.txt', 'w') as rfile:
    #         rfile.write(DDPG_config['TRAFFIC'].split('STAT:')[-1] + '\n')

    return folder


def pretty(f):
    try:
        float(f)
        return str.format('{0:.3f}', f).rstrip('0').rstrip('.')
    except:
        return str(f)

def softmax(x):
    return np.exp(x) / np.sum(np.exp(x), axis=0)