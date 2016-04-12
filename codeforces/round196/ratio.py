def reduceFract(n, d):
    def gcd(n, d):
        while d != 0:
            t = d
            d = n%d
            n = t
        return n
    greatest=gcd(n,d)
    n/=greatest
    d/=greatest
    return [n,d]

def ratio():
    x,y,p,q = map(float,raw_input().split())
    if (x/y == p/q):
        print '0' + '/' + '1'
    elif (x/y > p/q):
        X = (x*q)
        Y = (y*q)
        P = (y*p)
        Q = (y*q)
        #print n,d
        t = reduceFract(int(P),int(X))
        t[0] = t[1] - t[0]
        print str(t[0]) + '/' + str(t[1])
    else:
        X = (x*p)
        Y = (y*p)
        P = (x*p)
        Q = (q*x)
        #print n,d
        t = reduceFract(int(Q),int(Y))
        t[0] = t[1] - t[0]
        print str(t[0]) + '/' + str(t[1])
ratio()
