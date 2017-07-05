def bet():
    t = input()
    for p in xrange(t):
        x = input()
        if x<0.5:
            x = 1-x
        y = (x*10000)
        print y
        res = 2*y*(1-x) + y
        print res
bet()
