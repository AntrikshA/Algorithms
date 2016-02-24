import pandas as pd
import time
import numpy as np
from scipy.sparse import csr_matrix
import networkx as nx


def read_file():
    print "Loading edges file.."
    start = time.time()
    fil = pd.read_csv("higgs-retweet_network.edgelist", sep='\s',
                      names=['to', 'from', 'weight'], engine='python')

    end = time.time()
    print "File loaded in", end - start
    return fil

def create_graph(fil):
    E = [(x[1], x[2], {'weight': x[3]}) for x in fil.itertuples()]

    K = nx.Graph()
    K.add_edges_from(E)

    return K