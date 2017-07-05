from sys import stdin
def fgfs():
    data = (line for line in stdin.read().splitlines())
    for t in xrange(int(next(data))):
        n,k = map(int,next(data).split())
        a = []
        for i in xrange(n):
            t1,t2,t3 = map(int,next(data).split())
            a.append([t3,t2,t1])
        a.sort()
        #print a
        i = 0
        if n == 0:
            print '0'
        else:
            res = 1
            z = a[i][0]
            f = a[i][1]
            i += 1
            while i<n:
                while i<n and a[i][0] == z:
                    if a[i][2] >= f:
                        res += 1
                        f = a[i][1]
                    i += 1
                if i >= n:
                    break
                z = a[i][0]
                f = a[i][1]
                res += 1
                i += 1
            print res
fgfs()
