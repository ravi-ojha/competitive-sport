import math
from fractions import gcd
def bad_guys():
    for t in xrange(input()):
        n = input()
        c = 0
        b = n*n
        m = int(math.sqrt(n))
        for i in xrange(1,m+1):
            c += n/i
        c = c*2
        c = c - m**2
        d = gcd(c,b)
        print str(c/d) + "/" + str(b/d)
bad_guys()
