def spcandy():
    for t in xrange(input()):
        n,k = map(int,raw_input().split())
        if k == 0:
            print '0',n
        else:
            print n/k,n%k
spcandy()