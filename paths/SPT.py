import numpy as np
import operator
import time
import networkx as nx


def path_tree(s, K):

    distance, path = nx.single_source_dijkstra(K, s, weight='weight')

    H = K.subgraph(path)

    # print K

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
    distance, path = nx.single_source_dijkstra(
        K, s, weight='weight')

    return distance, path
