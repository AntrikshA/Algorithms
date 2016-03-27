%load_ext autoreload
%autoreload 2
from init import *
from LandmarksBasic import *
from LCA import *
from landmarksBFS import *
from select_landmarks import *
from SPT import *
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
fil = read_file("testedges2.txt")
G = create_graph(fil)
e = zip(fil['from'], fil['to'])
V = np.unique(e)
nx.draw_networkx(G,pos=nx.spring_layout(G),width=2)
plt.savefig('example2')
plt.close()
U,Udict = best_coverage(50,10,G,fil)
d = np.zeros((len(U),len(V)))
d = precompute(U,d,G,V)

import time

start = time.time()

for i in xrange(10):
    s,t = randm(V)
    s,t = 'A','E'
    print dist_LCA(s, t, U, G, d, Udict, V)
    print dist_SC(s, t, U, G, d, Udict, V)

print "time taken ..",time.time()-start/10
start = time.time()

for i in xrange(10):
    print shortest_path(s,G)[0][t]

print "time taken ..",time.time()-start/10
