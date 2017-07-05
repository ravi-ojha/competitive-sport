import math
def plz():
    for t in xrange(input()):
        l,d,s,c = map(int,raw_input().split())
        if math.log(l,2) <= (math.log(s,2) + (d-1)*math.log(c+1,2)):
            print 'ALIVE AND KICKING'
        else:
            print 'DEAD AND ROTTING'
plz()
