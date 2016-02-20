#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Algorithm 3 Landmarks-BFS
# Require: Graph G = (V, E), a set of landmarks U ⊂ V , an
# SPT parent link pu[v] precomputed for each u ∈ U, v ∈
# V .
# 1: function Landmarks-BFS(s,t)
# 2: S ← ∅
# 3: for u ∈ U do
# 4: S ← S ∪ Path-Tou(s,(u)) . (see Algorithm 2)
# 5: S ← S ∪ Path-Tou(t,(u))
# 6: end for
# 7: Let G[S] be the subgraph of G induced by S.
# 8: Apply BFS on G[S] to find a path π from s to t.
# 9: return |π|
# 10: end function

from extras import *
from LCA import *
from SPT import *
import networkx as nx


def landmarkBFS(s, t, U, fil):
    S = []

    E = [(x[1], x[2], {'weight': x[3]}) for x in fil.itertuples()]

    K = nx.Graph()
    K.add_edges_from(E)

    d, p = nx.single_source_dijkstra(
            K, s, target=t, weight='weight')
    
    for u in U:
        S += path_to_u(s,u,fil)         #Algorithm 2
        S += path_to_u(t,u,fil)

    G = nx.Graph()
    
    for i in S:
        G.add_path(i)

    d, pi = nx.single_source_dijkstra(
            G, s, target=t, weight='weight')

    return pi
