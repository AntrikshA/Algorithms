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
import numpy as np

def landmarks_basic(s,t,U):
	d = []
	for u in U:
		d += du[s]+du[t]

	dapprox = min(d)

	return dapprox

def precompute(G,fil):
	
	U = select(G,fil,k)

	all_ids = np.unique(fil.values)

	du = np.array((len(U)))
	for u in U:
		BFS(u)		#Implement
		for v in V:
			du[v] = distance(u,v)

