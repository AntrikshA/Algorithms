#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
    Algorithm 1 Landmarks-Basic
    Require: Graph G = (V, E), number of landmarks k.
    1: procedure Precompute
    2: U ← Select-Landmarks(G,k) . Algorithm 4
    3: for u ∈ U do
    4: Do a BFS traversal starting from u.
    5: For each v ∈ V store its distance from u as du[v].
    6: end for
    7: end procedure
    8: function Landmarks-Basic(s, t)
    9: dapprox ← minu∈U (du[s] + du[t])
    10: return dapprox
    11: end function
"""

from select_landmarks import *
from extras import *
from init import *
from SPT import *
import numpy as np
import operator
import networkx as nx


def distance(s, t, U, d, V):

    dapprox = 99999
    lm = None
    for u in U:
        if d[U.index(u), np.where(V == s)] + d[U.index(u), np.where(V == t)] < dapprox:
            dapprox = d[U.index(u), np.where(V == s)] + d[U.index(u), np.where(V == t)]
            lm = u

    return dapprox, lm


def precompute(U, d, G, V):
    # U = best_coverage(M, k, fil)            # Select_landmarks

    # e = zip(fil['from'], fil['to'])
    # V = np.unique(e)

    print "Collected vertices, calculating distances ..."

    # d = np.zeros((len(U), len(V)))

    for u in xrange(len(U)):
        for v in xrange(len(V)):
            d[u, v] = 99999

    for u in xrange(len(U)):

        print "Calculating for", U[u], "..."

        di = nx.single_source_dijkstra_path_length(G, U[u])
        for key in di.keys():
            v = np.where(V == key)
            d[u, v] = di[key]

    return d
