import itertools
def permuts():
    l =  list(itertools.permutations([1,2,3,4,5,6]))
    for i in l:
        if (6,5) in i:
            print i
permuts()
