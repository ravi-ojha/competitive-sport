def cng():
    for t in xrange(input()):
        a = [0]*100
        n,m = map(int,raw_input().split())
        k = n*2
        while(k < 100):
            a[k] = 1
            k = k+n
        k = m*2
        while(k < 100):
            a[k] = 1
            k = k+n
        print a
cng()
