import random
def print_random_phrase(d):
    print(d['DT'][random.randrange(0,len(d['DT']),1)],end=" ")
    print(d['JJ'][random.randrange(0,len(d['JJ']),1)],end=" ")
    print(d['NN'][random.randrange(0,len(d['NN']),1)])