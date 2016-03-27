#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
    Algorithm 2 LCA-based upper bounding algorithms
    Require: Graph G = (V, E), a landmark u ∈ V , a parent
    link pu[v] precomputed for each v ∈ V .
    1: function Path-Tou(s,π)
    Returns the path in the SPT pu from the vertex s
    to the closest vertex q belonging to the path π
    2: Result ← (s) . Sequence of 1 element.
    3: while s /∈ π do
    4: s ← pu[s]
    5: Append s to Result
    6: end while
    7: return Result . (s, pu[s], pu[pu[s]], . . . , q), q ∈ π
    8: end function
    9: function Distance-LCAu(s,t)
    10: π(1) ← Path-Tou(s,(u) )
    11: π(2) ← Path-Tou(t, π(1))
    12: LCA ← Last element of π
    13: π(3) ← Path-Tou(s,(LCA) )
    14: return |π
    15: end function
    16: function Distance-SCu(s,t)
    17: π(1) ← Path-Tou(s,(u) )
    18: π(2) ← Path-Tou(t, π(1))
    19: LCA ← Last element of π
    20: π(3) ← Path-Tou(s,(LCA) )
    21: Best ← |π(2)| + |π(3)|
    22: for (w, w0
    23: Current ← |πs,w| + |πw,w0 | + |πw0
    24: Best ← min(Current,Best)
    25: end for
    26: return Best
    27: end function
"""

from SPT import *
from LandmarksBasic import *
from itertools import permutations, repeat, product


def path_to_u(s, lm, d, Udict):

    d1, p = shortest_path(s, Udict[lm])

    return p[lm]


def dist_LCA(s, t, U, G, d, Udict, V):

    d3, lm = distance(s, t, U, d, V)

    pi1 = path_to_u(s, lm, d, Udict)

    pi2 = path_to_u(t, lm, d, Udict)

    LCA = set(pi1).intersection(pi2)
    # print 'Number of nodes in LCA', len(LCA)

    best = 99999999
    lca = None
    for l in LCA:
        # print 'for', l, '...'
        d1, p1 = shortest_path(s, Udict[lm])
        d2, p2 = shortest_path(t, Udict[lm])
        try:
            dapprox = d1[l] + d2[l]
        except TypeError:
            continue
        if dapprox < best:
            d3, pi3 = shortest_path(s, Udict[lm])
            d4, pi4 = shortest_path(t, Udict[lm])
            best = dapprox
            lca = l

    return best, lca, pi3[lca], pi4[lca]


def dist_SC(s, t, U, G, d, Udict, V):

    d3, lm = distance(s, t, U, d, V)

    pi1 = path_to_u(s, lm, d, Udict)

    pi2 = path_to_u(t, lm, d, Udict)

    LCA = set(pi1).intersection(pi2)
    # print 'Number of nodes in LCA', len(LCA)

    best = 99999999
    lca = None
    for l in LCA:
        # print 'for', l, '...'
        d1, p1 = shortest_path(s, Udict[lm])
        d2, p2 = shortest_path(t, Udict[lm])
        try:
            dapprox = d1[l] + d2[l]
        except TypeError:
            continue
        if dapprox < best:
            d3, pi3 = shortest_path(s, Udict[lm])
            d4, pi4 = shortest_path(t, Udict[lm])
            best = dapprox
            lca = l

    A = Udict[lm].subgraph(pi4[lca])
    B = Udict[lm].subgraph(pi4[lca])

    e = G.edges()

    e = set([tuple(sorted(x)) for x in e])

    i = set(product(pi3[lca], pi4[lca]))
    i = i - (set(A.edges()) & set(B.edges()))
    i = set([tuple(sorted(x)) for x in i])
    sc_edges = [i.intersection(e)]
    # print sc_edges
    # print i
    # print G.edges()
    # print set(A.edges())
    # print set(B.edges())
    # print set(A.edges()) & set(B.edges())

    current = best
    dist = 0
    for edge in sc_edges[0]:
        w, w1 = edge
        d1 = shortest_path(s, Udict[lm])[0][w]
        d3 = shortest_path(w1, Udict[lm])[0][t]
        # print shortest_path(w1, Udict[lm])[0]
        # print dist, d1, d3
        dist = d1 + d3

        d2 = shortest_path(w, Udict[lm])[0][w1]
        current = dist + d2
        best = min(current, best)

    return best
