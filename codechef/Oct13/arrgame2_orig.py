import math
def arrgame2():
    for t in xrange(input()):
        n = input()
        res = 0.0
        pre = 0
        a = map(int,raw_input().split())
        b = map(int,raw_input().split())
        c = []
        d = []
        for i in xrange(n):
            t = math.log(a[i])/a[i]
            c.append(t)
            t = math.log(b[i])/b[i]
            d.append(t)
        #print c,d
        c.sort()
        d.sort()
        if c[0] > d[n-1]:
            res = 1.0*n
        elif c[n-1] <= d[0]:
            res = 0.0
        else:
            j = 0
            for i in xrange(n):
                while j!=n and c[i] > d[j] :
                    pre+=1
                    j+=1
                res += pre
                if j==n:
                    res = res + pre*(n-i-1)
                    break
            res /= n
        print res
arrgame2()
