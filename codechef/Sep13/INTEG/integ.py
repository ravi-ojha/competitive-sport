def makePos(i):
    if i < 0:
        return -i
    return i
def integ():
    n = input()
    a = map(int,raw_input().split())
    x = input()
    b = []
    for i in a:
        if i < 0:
            b.append(i)
    #print b
    b.sort()
    #print b
    #print len(b)
    res = 0
    if b == []:
        print '0'
    else:
        if(len(b) < x):
            for i in b:
                res = res + makePos(i)
        else:
            t = b[x-1];
            t = makePos(t)
            res = x*t
            i = 0
            while i < (x-1):
                res = res + makePos(b[i]) - t;
                i += 1
        print res
integ()
