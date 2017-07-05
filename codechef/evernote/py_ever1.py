def ever1():
    n = input()
    a = []
    for i in xrange(n):
        a.append(input())
    for t in xrange(4):
        mx = -99999999999999999999
        j = 0
        for i in xrange(n):
            if a[i] > mx:
                mx = a[i]
                j = i
        a[j] = -99999999999999999999
        print mx
ever1()
