import numpy as np

header = ['CC','CD','DT','EX','FW','IN','JJ','JJR','JJS','LS','MD','NN','NNS','NNP','NNPS','PDT',\
    'POS','PRP','PRPD','RB','RBR','RBS','RP','SYM','TO','UH','VB','VBD','VBG','VBN','VBP','VBZ','WDT',\
    'WP','WPD','WRB','SentenceLength','WordCount',\
    'FunctionWordCount',\
    'count_errors','Sentiment',\
    'Polarity']

def InformationGain(a):
    print a

if __name__ == '__main__':
    for i in header:
        print i,':',InformationGain(i)