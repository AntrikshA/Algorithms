import time
import numpy as np
from decimal import *
import pandas as pd
from pandas import Categorical
from scipy.sparse import csr_matrix, csgraph, csc_matrix


def PageRank():

    print "extracting file data..."
    start = time.time()
    webGoogle = pd.read_csv('web-Google.txt', sep='\t', comment='#', names=['from', 'to'])
    end = time.time()
    print "Time to read the file :", end - start

    print "initialising matrices..."
    start = time.time()
    data = np.repeat(1, webGoogle.shape[0])
    categories = np.unique(webGoogle.values)
    size = len(categories)

    col_ind = pd.Categorical(webGoogle['from'], categories=categories).codes
    row_ind = pd.Categorical(webGoogle['to'], categories=categories).codes

    M = csr_matrix((data, (row_ind, col_ind)))

    end = time.time()
    print "Time to initialise matrices :", end - start

    start = time.time()
    beta = 0.85
    rank = np.ones(size)
    t = 1
    while 1:
        rank0 = rank.copy()
        rankp = np.zeros(size)
        for i in categories:
            try:
                for j in range(i):
                    rankp[i] +=  float(beta * float(float(rank[j]) / float(M[i].getnnz())))
            except ZeroDivisionError:
                rankp[i] +=  0
                continue

        S = float(sum(rankp))

        for i in categories:
            rank[i] = float(float(rankp[i]) + float((1-S)/float(size)))

        t += 1
        if rank.all() == rank0.all():
            break

    end = time.time()
    print "Time to calculate ranks :", end - start
    print "Iterations :",t
    print float(rank[99]/float(sum(rank)))


if __name__ == '__main__':
    PageRank()