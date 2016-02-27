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
U,Udict = best_coverage(100,10,G,fil)
