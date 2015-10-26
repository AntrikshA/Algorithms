import time
import numpy as np
from decimal import *

def getEdges():
    edges = []
    nodes = []
    print "extracting file data..."
    start = time.time()

    with open("web-Google.txt") as f:
        for i in f.readlines():
            if '#' not in i:
                node = i.split('\n')[0].split('\t')
                nodes += node
                edges += [node]

    nodes = list(set(nodes))
    end = time.time()
    print "Time to read the file :", end - start
    return edges, nodes

def PageRank():
    edges, nodes = getEdges()

    print "initialising matrices..."
    start = time.time()
    M = np.zeros((len(nodes)+1,len(nodes)+1,), dtype=np.float)
    L = np.full((len(nodes)+1,len(nodes)+1,), fill_value= \
        (Decimal(1/Decimal(len(nodes)))), dtype=np.float)
    A = np.zeros((len(nodes)+1,len(nodes)+1,), dtype=np.float)
    
    for node in nodes:
        count = 0
        ends = []
        for edge in edges:
            if node==edge[0]:
                count += 1
                ends += [edge[1]]
        for end in ends:
            M[nodes.index(end)][nodes.index(node)] = Decimal(1/Decimal(count))

    for i in range(0,len(nodes)+1):
        for j in range(0,len(nodes)+1):
            A[i][j] += [ ((0.85 * M[i][j]) + (0.15 * L[i][j])) ]

    # print A
    end = time.time()
    print "Time to initialise matrices :", end - start
    
    print "Calculating rank..."
    rank = np.full((len(nodes)+1,), fill_value= \
        (Decimal(1/Decimal(len(nodes)))), dtype=np.float)

    start = time.time()
    while 1:
        prevrank = rank
        for i in range(0,len(nodes)+1):
            for j in range(0,len(nodes)+1):
                rank[j] = A[i][j] * (rank[j]) 

        if rank.all() == prevrank.all():
            break

    end = time.time()
    print "Time to calculate ranks :", end-start
    print rank[rank.index(99)]

if __name__ == '__main__':
    PageRank()