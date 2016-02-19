#!/usr/bin/env python
# -*- coding: utf-8 -*-
from init import *
import random

def random(nodes):
    import random
    a = random.randint(0,len(nodes)-1)
    b = random.randint(0,len(nodes)-1)
    return nodes[a],nodes[b]

def BFS(graph, start):      #Implement BFS here
    visited=[], queue = [start]
    while queue:
        vertex = queue.pop(0)
        if vertex not in visited:
            visited.add(vertex)
            queue.extend(graph[vertex] - visited)
    return visited

# def calc_dijkstra(G):
#     # pass
#     return dijkstra(csgraph, directed=True)
    

def distance(s,t,U):

    dapprox = min([distance(s,u)+distance(u,t) for u in U])

    return dapprox
