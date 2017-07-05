def edgeACRush():
    for t in xrange(input()):
        a = []
        res = 0
        count = 0
        countb = 0
        b = []
        bb = []
        n,m,c,d = map(int,raw_input().split())
        for i in xrange(n):
            t = raw_input()
            a.append(t)
        for i in xrange(n):
            for j in xrange(m):
                if a[i][j] == 'B':
                    b.append([str(i+1),str(j+1)])
                    #res = res + d
                    count += 1
                else:
                    bb.append([str(i+1),str(j+1)])
                    #res = res + d
                    countb += 1
        if count > n*m/2:
            print countb
            for i in xrange(countb):
                print '2',' '.join(bb[i])
        else:
            print count
            for i in xrange(count):
                print '3',' '.join(b[i])
edgeACRush()
