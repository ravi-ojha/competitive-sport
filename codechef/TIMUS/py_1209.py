from sys import stdin
import math
def p1209():
    data = (line for line in stdin.read().splitlines())
    res = []
    for t in xrange(int(next(data))):
        k = int(next(data))
        k -= 1
##        x = 1 + 8*k
##        f = math.sqrt(x)
##        i = int(f)
##        if f == i:
##            res.append('1')
##        else:
##            res.append('0')
        n = int(math.sqrt(k*2))
        if n*(n+1) == k*2:
            res.append('1')
        else:
            res.append('0')
    print ' '.join(res)
p1209()
