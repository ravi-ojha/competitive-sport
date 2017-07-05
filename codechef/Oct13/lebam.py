def lebam():
    for t in xrange(input()):
        n = input()
        a = map(int,raw_input().split())
        b = map(int,raw_input().split())
        res = -1
        toget = sum(b) - sum(a)
        if n == 2:
            if all(a[i] == b[i] for i in xrange(n)):
                print '0'
            elif((a[0]-b[0]) + (a[1]-b[1])) == 0:
                print abs(a[0]-b[0])
            else:
                print '-1'
        else:
            if n!=2:
                if toget%(n-2) == 0:
                    res = toget/(n-2)
                else:
                    res = abs(b[0]-a[0])
            if res>=0:
                for i in xrange(n):
                    temp = res - b[i] + a[i]
                    if temp%2 != 0 or temp < 0:
                        res = -1
                        break
            if res<0:
                print "-1"
            else:
                print res
lebam()
