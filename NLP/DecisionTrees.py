#Decision Trees to decide end of sentence

# Node class
class Node:
  
    # Function to initialize the node object
    def __init__(self, data):
        self.data = data  # Assign data
        self.left = None  
        self.right = None  

class DecisionTrees:
	# Main class
	# first have a defined dataset of sentences with their ends on a period "."
	# Calculate info gain on each of the attributes

	def __init__(self):
		print 'Welcome to Decision Trees'
		self.train()
		self.test()
		self.classify()

	def BuildSubTree(self,Node n,DATA):
		# Node 
		(n->split, DL, DR) = FindBestSplit(DATA)
		
		if StoppingCriteria(DL):
			n->left = FindPrediction(DL)
		else:
			BuildSubTree(n->left,DL)

		if StoppingCriteria(DR):
			n->right = FindPrediction(DR)
		else:
			BuildSubTree(n->right,DR)


	def train(self):
		print 'Training Decision Trees'

	def test(self):
		# self.train()
		print 'Testing Decision Trees'
		print 'Checking for accuracy'

	def classify(self):
		print 'Taking the input and classifying'

