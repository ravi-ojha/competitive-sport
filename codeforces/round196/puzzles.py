def puzzles():
    n,m = map(int,raw_input().split())
    a = map(int,raw_input().split())
    a.sort()
    b = []
    for i in xrange(n-1,m):
        b.append(a[i] - a[i-(n-1)])
    #print b
    print min(b)
puzzles()
