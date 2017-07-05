def ever2():
    n = input()
    a = []
    m = 1
    for i in xrange(n):
        a.append(input())
        m = m*a[i]
##    for i in xrange(n):
##        print m/a[i]
    left = [0]*n
    right = [0]*n
    i = 0
    m = 1
    while i < n:
        m = m*a[i]
        left[i] = m
        i += 1
    i = n-1
    m = 1
    while i >= 0:
        m = m*a[i]
        right[i] = m
        i -= 1
    #print left
    #print right
    for i in xrange(n):
        if i == 0:
            print right[1]
        elif i == n-1:
            print left[n-2]
        else:
            print left[i-1]*right[i+1]
ever2()
