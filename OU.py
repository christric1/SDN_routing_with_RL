import numpy as np
from scipy.stats import norm


# Ornstein-Uhlenbeck Process
class OU(object):

    def __init__(self, processes, mu=0, theta=0.15, sigma=0.3):
        self.dt = 0.1
        self.mu = mu
        self.theta = theta
        self.sigma = sigma
        self.processes = processes
        self.state = np.ones(self.processes) * self.mu

    def reset(self):
        self.state = np.ones(self.processes) * self.mu

    def evolve(self):
        X = self.state
        dw = norm.rvs(scale=self.dt, size=self.processes)
        dx = self.theta * (self.mu - X) * self.dt + self.sigma * dw
        self.state = X + dx
        return self.state