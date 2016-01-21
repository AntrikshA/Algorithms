#Decision Trees to decide end of sentence

import math

# Node class
class Node:
  
    # Function to initialize the node object
    def __init__(self, data):
        self.data = data
        self.left = None 
        self.right = None 
        self.split = None


class DecisionTrees:
	# Main class
	# first have a defined dataset of sentences with their ends on a period "."
	# Calculate info gain on each of the attributes

	def __init__(self):
		# print 'Welcome to Decision Trees'

	def Variance(self,DATA):
		mean = float(sum(DATA))/float(len(DATA))

		var = 0.0
		for i in DATA:
			var += float(i-mean)*float(i-mean)

		var = var/float(len(DATA))

		return var

	def InformationGain(self,DATA):
		val_freq = {}
		# Calculate the frequency of each of the values in the target attribute
	    for record in data:
	        if (val_freq.has_key(record[attr])):
	            val_freq[record[attr]] += 1.0
	        else:
	            val_freq[record[attr]]  = 1.0

		def _entropy(data, target_attr):

		    data_entropy = 0.0

		    # Calculate the entropy of the data for the target attribute
		    for freq in val_freq.values():
		        data_entropy += (-freq/len(data)) * math.log(freq/len(data), 2) 

		    return data_entropy

		def _gain(data, attr, target_attr):

		    # val_freq = {}
		    subset_entropy = 0.0

		    # Calculate the sum of the entropy for each subset of records 
		    # weighted by their probability of occuring in the training set.
		    for val in val_freq.keys():
		        val_prob = val_freq[val] / sum(val_freq.values())
		        data_subset = [record for record in data if record[attr] == val]
		        subset_entropy += val_prob * entropy(data_subset, target_attr)

		# Subtract the entropy of the chosen attribute from the entropy of the whole
		# data set with respect to the target attribute (and return it)
	    return (entropy(data, target_attr) - subset_entropy)

	def value(DATA,i):
		DL = DATA[:i]
		DR = DATA[i:]

		out = len(DATA)*self.Variance(DATA) - (len(DL)*self.Variance(DL)+len(DR)*self.Variance(DR))

		return out


	def FindBestSplit(self,DATA):

		print 'Finding Best split in ', DATA

		lst = []
		for i in len(DATA):
			lst += [[self.value(DATA,i),i]]

		lst = [sorted(lst), lambda pair: pair[0]]

		return DATA[:lst[-1][1]], DATA[lst[-1][1]:]

	def BuildSubTree(self,Node n ,DATA):
		# Node n 
		# n->split, 
		DL, DR = self.FindBestSplit(DATA)
		
		if StoppingCriteria(DL):
			n->left = FindPrediction(DL)
		else:
			BuildSubTree(n->left,DL)

		if StoppingCriteria(DR):
			n->right = FindPrediction(DR)
		else:
			BuildSubTree(n->right,DR)


