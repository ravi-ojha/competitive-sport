def ppnum():
    res = 0
    t = 1
    for i in xrange(999999000,1000000001):
        t = i*len(str(i))
        #print t
        res += t
    res = res % 1000000007
    print 'res ' + str(res)
ppnum()
