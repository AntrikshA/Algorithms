import pandas as pd
import time
import numpy as np
from scipy.sparse import csr_matrix

def read_file():
	print "Loading edges file.."
	start = time.time()
	fil = pd.read_csv("higgs-retweet_network.edgelist", sep='\s',
	                  names=['to', 'from', 'weight'], engine='python')

	end = time.time()
	print "File loaded in",end-start
	return fil
