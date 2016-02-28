%load_ext autoreload
%autoreload 2
from init import *
from LandmarksBasic import *
from LCA import *
from landmarksBFS import *
from select_landmarks import *
from SPT import *
fil = read_file()
G = create_graph(fil)
e = zip(fil['from'], fil['to'])
V = np.unique(e)
U,Udict = best_coverage(50,10,G,fil)
d = np.zeros((len(U),len(V)))
d = precompute(U,d,G,V)
s = 117539
t = 168675
dist_LCA(s, t, U, G, d, Udict, V)
dist_SC(s, t, U, G, d, Udict, V)
shortest_path(s,t,G)[0][t]
