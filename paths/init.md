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
U,Udict = best_coverage(10,10,G,fil)
d = np.zeros((len(U),len(V)))
d = precompute(U,d,G,V)
s = 3549
t = 7627
dapprox,lm = distance(s, t, U, d, V)
