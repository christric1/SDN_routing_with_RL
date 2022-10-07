from Environment import OmnetLinkweightEnv

import argparse
import numpy as np
from DDPG import DDPG
from itertools import count
from helper import setup_run


parser = argparse.ArgumentParser()
parser.add_argument('--mode', default='train', type=str) # mode = 'train' or 'test'
parser.add_argument('--tau',  default=0.005, type=float) # target smoothing coefficient
parser.add_argument('--target_update_interval', default=1, type=int)
parser.add_argument('--test_iteration', default=10, type=int)

parser.add_argument('--learning_rate', default=1e-4, type=float)
parser.add_argument('--gamma', default=0.99, type=int) # discounted factor
parser.add_argument('--capacity', default=1000000, type=int) # replay buffer size
parser.add_argument('--batch_size', default=100, type=int) # mini batch size
parser.add_argument('--seed', default=False, type=bool)
parser.add_argument('--random_seed', default=9527, type=int)

# optional parameters
parser.add_argument('--load', default=False, type=bool) # load model
parser.add_argument('--exploration_noise', default=0.1, type=float)
parser.add_argument('--log_interval', default=50, type=int) #
parser.add_argument('--max_episode', default=15, type=int) # num of games
parser.add_argument('--MAX_STEPS', default=100, type=int) # num of games
parser.add_argument('--update_iteration', default=200, type=int)
parser.add_argument('--EXPERIMENT', default='runs/', type=str)
parser.add_argument('--ENV', default='label', type=str)
parser.add_argument('--ACTIVE_NODES', default=23, type=int)
parser.add_argument('--ACTUM', default="NEW", type=str)
parser.add_argument('--PRAEMIUM', default="AVG", type=str)
parser.add_argument('--STATUM', default="T", type=str)
parser.add_argument('--TRAFFIC', default="DIR", type=str)
args = parser.parse_args()


if __name__ == "__main__":

    # Randon seed
    if args.seed:
        # torch.manual_seed(args.random_seed)
        np.random.seed(args.random_seed)

    # SETUP STARTS HERE
    if args.mode == 'train':
        folder = setup_run(args)
    elif args.mode == 'test':
        folder = args.EXPERIMENT

    # Generate an environment
    env = OmnetLinkweightEnv(args, folder)
    action_dim, state_dim = env.a_dim, env.s_dim

    # The agent
    agent = DDPG(state_dim, action_dim, 1.0, args, folder)

    ep_r = 0
    print("OMNeT++ Experiment Start.")

    # test 
    if args.mode == 'test':
        agent.load()
        for i in range(args.test_iteration):
            state = env.reset()
            for t in count():
                action = agent.select_action(state)
                next_state, reward = env.step(np.float32(action))
                ep_r += reward
                if t >= args.max_length_of_trajectory:
                    print("Ep_i \t{}, the ep_r is \t{:0.2f}, the step is \t{}".format(i, ep_r, t))
                    ep_r = 0
                    break
                state = next_state

    # train
    elif args.mode == 'train':
        if args.load: agent.load()
        state = env.reset()
        total_step = 0
        for i in range(args.max_episode):
            total_reward = 0
            step = 0
            for t in range(args.MAX_STEPS):
                action = agent.select_action(state)
                action = (action + np.random.normal(0, args.exploration_noise, size=env.a_dim)).clip(
                    0, 1.0)

                next_state, reward = env.step(action)
                agent.writer.add_scalar('reward', -reward, global_step=(i*args.MAX_STEPS)+t)
                agent.replay_buffer.push((state, next_state, action, reward))

                state = next_state
                step += 1
                total_reward += reward

            total_step += step + 1
            print("Total T:{} Episode: \t{} Total Reward: \t{:0.2f}".format(total_step, i, total_reward))
            agent.update()

            if i % args.log_interval == 0:
                agent.save()
    else:
        raise NameError("mode wrong!!!")

    env.end()  # This is for shutting down
    print("Finish.")