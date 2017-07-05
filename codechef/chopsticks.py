def chopsticks():
    n,d = map(int,raw_input().split())
    a = []
    for i in xrange(n):
        t = input()
        a.append(t)
    if n == 1:
        print '0'
    else:
        a.sort()
##        if (a[1] - a[0]) <= d:
##            count = 1
##        else:
##            count = 0
##        for i in xrange(1,n-1):
##            if (a[i+1] - a[i]) <= d or (a[i] - a[i-1]) <= d:
##                count += 1
##        if (a[n-1] - a[n-2]) <= d:
##            count += 1
        i = 0
        res = 0
        while i<(n-1):
            count = 1
            if i<(n-1) and (a[i+1] - a[i]) > d:
                i += 1
                continue
            while (i < (n-1)) and (a[i+1] - a[i]) <= d:
                
                count += 1
                #print count
                i += 1
            res = res + count/2
        print res
chopsticks()
