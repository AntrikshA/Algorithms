#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Algorithm 1 Landmarks-Basic
# Require: Graph G = (V, E), number of landmarks k.
# 1: procedure Precompute
# 2: U ← Select-Landmarks(G,k) . Algorithm 4
# 3: for u ∈ U do
# 4: Do a BFS traversal starting from u.
# 5: For each v ∈ V store its distance from u as du[v].
# 6: end for
# 7: end procedure
# 8: function Landmarks-Basic(s, t)
# 9: dapprox ← minu∈U (du[s] + du[t])
# 10: return dapprox
# 11: end function

from select_landmarks import *
from extras import *
from init import *
from SPT import *
import numpy as np
import operator


def distance(s, t, U):

    dapprox = min([sum(shortest_dist(s, u, fil).values()) +
                   sum(shortest_dist(u, t, fil).values()) for u in U])

    return dapprox


def precompute(M, k, fil):
    U = best_coverage(M, k, fil)

    V = np.unique(fil.values)

    d = np.zeros((len(U), len(V)))
    for u in xrange(len(U)):
        for v in xrange(len(V)):
            d[u, v] = sum(shortest_dist(U[u], V[v], fil).values())

    return d
