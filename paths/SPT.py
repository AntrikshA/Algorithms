import numpy as np
import operator
import time
import networkx as nx

# To make Shortest path trees for all of the landmarks in U


def path_tree(s, K):

    distance, path = nx.single_source_dijkstra(K, s, weight='weight')

    H = K.subgraph(path)

    return H


def shortest_dist(s, t, K):

    try:
        distance, path = nx.single_source_dijkstra(
            K, s, target=t, weight='weight')
    except KeyError:
        path = {}
        distance = 0

    return distance


def shortest_path(s, K):

    try:
        distance, path = nx.single_source_dijkstra(
            K, s, weight='weight')
    except KeyError:
        path = None
        distance = {s: None}

    return distance, path
