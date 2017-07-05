from fractions import gcd
def lineprob():
    for t in xrange(input()):
        x1,y1,x2,y2 = map(int,raw_input().split())
        x = abs(x1-x2)
        y = abs(y1-y2)
        print x + y - gcd(x,y)
lineprob()
