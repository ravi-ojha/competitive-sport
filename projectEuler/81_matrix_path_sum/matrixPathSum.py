n = 80
def matrixPathSum():
    a = []
    for i in xrange(n):
        t = map(int,raw_input().split(','))
        a.append(t)
    for i in xrange(1,n):
        a[i][0] += a[i-1][0]
    for j in xrange(1,n):
        a[0][j] += a[0][j-1]
    i = 1
    j = 1
    while i < n:
        j = 1
        while j < n:
            t = min(a[i-1][j], a[i][j-1])
            #print t
            a[i][j] = a[i][j] + t
            j += 1
        i += 1
    print a[n-1][n-1]
matrixPathSum()
