from init import *
from LandmarksBasic import *
from LCA import *
from landmarksBFS import *
from select_landmarks import *
from SPT import *
import numpy as np
import networkx as nx
import time
import matplotlib.pyplot as plt

fil = read_file("testedges3.txt")
G = create_graph(fil)
e = zip(fil['from'], fil['to'])
V = np.unique(e)

start = time.time()
print 'Drawing graph ...'
nx.draw_networkx(G, pos=nx.spring_layout(G), width=2)
plt.savefig('example3')
plt.close()
print 'Graph drawn in ..',time.time()
U, Udict = best_coverage(50, 5, G, fil)
d = np.zeros((len(U), len(V)))
d = precompute(U, d, G, V)

# s,t = randm(V)
# print s,t
# print dist_LCA(s, t, U, G, d, Udict, V)
# print dist_SC(s, t, U, G, d, Udict, V)
# print shortest_path(s, G)[0][t]

# l = list(set(product(V, V)))

l = []
for i in xrange(100):
    s, t = randm(V)
    l += [(s, t)]

# outlca=[]
# start = time.time()
# for i in l:
#     s, t = i
#     dist_LCA(s, t, U, G, d, Udict, V)[0]

# print "time taken for LCA ..", "{:.10f}".format((time.time() - start) / len(l))

outsc = []
start = time.time()
for i in l:
    s, t = i
    outsc += [dist_SC(s, t, U, G, d, Udict, V)]

print "time taken for SC ..", "{:.10f}".format((time.time() - start) / len(l))

out = []
start = time.time()
for i in l:
    s, t = i
    out += [shortest_path(s, G)[0][t]]

print "time taken for dijkstra ..", "{:.10f}".format((time.time() - start) / len(l))
# print outsc,out
print max(outsc), max(out)
print reduce(lambda x, y: x + y, outsc) / len(outsc), reduce(lambda x, y: x + y, out) / len(out)
