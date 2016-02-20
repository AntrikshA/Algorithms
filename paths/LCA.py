#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Algorithm 2 LCA-based upper bounding algorithms
# Require: Graph G = (V, E), a landmark u ∈ V , a parent
# link pu[v] precomputed for each v ∈ V .
# 1: function Path-Tou(s,π)
# Returns the path in the SPT pu from the vertex s
# to the closest vertex q belonging to the path π
# 2: Result ← (s) . Sequence of 1 element.
# 3: while s /∈ π do
# 4: s ← pu[s]
# 5: Append s to Result
# 6: end while
# 7: return Result . (s, pu[s], pu[pu[s]], . . . , q), q ∈ π
# 8: end function
# 9: function Distance-LCAu(s,t)
# 10: π(1) ← Path-Tou(s,(u) )
# 11: π(2) ← Path-Tou(t, π(1))
# 12: LCA ← Last element of π
# 13: π(3) ← Path-Tou(s,(LCA) )
# 14: return |π
# 15: end function
# 16: function Distance-SCu(s,t)
# 17: π(1) ← Path-Tou(s,(u) )
# 18: π(2) ← Path-Tou(t, π(1))
# 19: LCA ← Last element of π
# 20: π(3) ← Path-Tou(s,(LCA) )
# 21: Best ← |π(2)| + |π(3)|
# 22: for (w, w0
# 23: Current ← |πs,w| + |πw,w0 | + |πw0
# 24: Best ← min(Current,Best)
# 25: end for
# 26: return Best
# 27: end function

from SPT import *

def path_to_u(s,u,fil):
	"""Returns path in the SPT"""
	result = []

	p = shortest_path(s,u,fil)
	result.append(p)

	return result

def dist_LCA(s,t,fil):
	pi1 = path_to_u(s,u)
	pi2 = path_to_u(t,pi1)
	LCA = pi2[-1]
	pi3 = path_to_u(s,LCA)

	return pi2+pi3


def dist_SC(s,t,fil):
	pi1 = path_to_u(s,u)
	pi2 = path_to_u(t,pi1)
	LCA = pi2[-1]
	pi3 = path_to_u(s,LCA)

	best = pi2 + pi3

	l = set(pi2*pi3).intersection(E)

	for w,w1 in l:
		current = 1#Not understanding
		best = min(current,best)

	return best
