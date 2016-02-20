import numpy as np
import operator
import time
import networkx as nx

# To make Shortest path trees for all of the landmarks in U
def path_tree(s, fil):

    e = zip(fil['from'], fil['to'])

    E = [(x[1], x[2], {'weight': x[3]}) for x in fil.itertuples()]

    K = nx.Graph()
    K.add_edges_from(E)

    distance, path = nx.single_source_dijkstra(K, s, weight='weight')

    return path

def shortest_dist(s, t, fil):

    e = zip(fil['from'], fil['to'])

    E = [(x[1], x[2], {'weight': x[3]}) for x in fil.itertuples()]

    K = nx.Graph()
    K.add_edges_from(E)

    try:
        distance, path = nx.single_source_dijkstra(
            K, s, target=t, weight='weight')
    except KeyError:
        path = None
        distance = 0

    return distance

def shortest_path(s, t, fil):

    e = zip(fil['from'], fil['to'])

    E = [(x[1], x[2], {'weight': x[3]}) for x in fil.itertuples()]

    K = nx.Graph()
    K.add_edges_from(E)

    try:
        distance, path = nx.single_source_dijkstra(
            K, s, target=t, weight='weight')
    except KeyError:
        path = None
        distance = 0

    return path

def shortest_path_list(s,t,fil):
    E = [(x[1], x[2], {'weight': x[3]}) for x in fil.itertuples()]

    K = nx.Graph()
    K.add_edges_from(E)

    distance = 99
    path = []
    
    for i in t:
        try:
            d, p = nx.single_source_dijkstra(
                K, s, target=i, weight='weight')
        except KeyError:
            p = None
            d = None
        if distance > d:
            distance = d
            path = p

    return path