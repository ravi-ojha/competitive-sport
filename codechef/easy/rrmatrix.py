def rrmatrix():
    for t in xrange(input()):
        n,m = map(int,raw_input().split())
        if n == 1:
            print m
        elif m == 1:
            print n
        elif m == n:
            print n
        else:
            if m%2 == 1 and n%2 == 1:
                if m == (2*n - 1):
                    print n
                elif n == (2*m - 1):
                    print m
                else:
                    print '3'
            else:
                print '2'
rrmatrix()
