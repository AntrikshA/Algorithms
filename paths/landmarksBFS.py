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

def landmarkBFS(s,t,U):
	S = []
	
	#U = {u1 , u2 , . . . , uk } of k landmarks
	for u in U:				#U unknown
		S += path_to_u(s,u)			#Algorithm 2
		S += path_to_u(t,u)

	G[S] = subgraph(G,S)

	pi = BFS(s,t)

	return pi
