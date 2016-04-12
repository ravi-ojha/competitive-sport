def second():
    n = input()
    w = []
    for i in xrange(n):
        tmp = map(int,raw_input().split())
        w.append(tmp)
    a = []
    b = []
    for i in xrange(n):
        tmp = [0.0]*n
        a.append(tmp)
    for i in xrange(n):
        tmp = [0.0]*n
        b.append(tmp)
    i = 0
    j = 0
    while i<n:
        j = i
        while j<n:
            if i == j:
                a[i][j] = float(w[i][j])
                b[i][j] = 0.0
            else:
                a[i][j] = (w[i][j] + w[j][i])/2.0
                a[j][i] = a[i][j]
                if abs(w[i][j]) < abs(w[j][i]):
                    b[i][j] = (a[i][j] - w[i][j])*(-1.0)
                    b[j][i] = (-1.0)*b[i][j]
                else:
                    b[i][j] = (a[i][j] - w[i][j])*(1.0)
                    b[j][i] = (-1)*b[i][j]
            j += 1
        i += 1
    #print a
    #print b
    for z in a:
        for y in z:
            print ('%.8f' % y),
        print ''
    for z in b:
        for y in z:
            print ('%.8f' % y),
        print ''
second()
