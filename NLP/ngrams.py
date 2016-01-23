# N grams

import re
from itertools import izip
import collections

def ngrams(n,text):

	sentences=re.split('[?\.!;\n]+',text)
	
	# print sentences[:5]

	bigrams = []
	trigrams = []

	for sentence in sentences:

		sentence = '<s> '+ text+' </s>' 
		wordlist=re.split('[\s?\.!,]+',sentence)

		bigrams += [' '.join(pair) for pair in izip(wordlist[:-1], wordlist[1:])]
		trigrams += [' '.join(pair) for pair in izip(wordlist[:-1], wordlist[1:], wordlist[2:])]
		
	bigrams = collections.Counter(bigrams)
	trigrams = collections.Counter(trigrams)

	return bigrams, trigrams