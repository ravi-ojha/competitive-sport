def chrect():
    t = input()
    for p in xrange(t):
        n,m,k = map(int,raw_input().split())
        if m == 1 and n == 1:
            print '0'
        elif m == 2 and n == 1:
            print '0'
        elif m == 1 and n == 2:
            print '0'
        else:
            if k == 1:
                print 1
            elif m == 1 or n == 1:
                print k
            else:
                if k&1:
                    print (k+1)/2
                else:
                    print k/2
chrect()
