def seasor():
    for t in xrange(input()):
        res = []
        n,k = map(int,raw_input().split())
        a = map(int,raw_input().split())
        z = n - k + 1
        flag = 0
        l = 0
        size = (n*n)/k
        size = size + 1000
        asorted = sorted(a)
        if z<=0 or n == 1:
            print '0'
        else:
            while True:
                if flag == 1:
                    break
                for i in xrange(1,z+1):
                    a[i-1:i+k-1] = sorted(a[i-1:i+k-1])
                    #print a
                    res.append(str(i))
                    l += 1
                    if a == asorted or l == size:
                        flag = 1
                        break
            print len(res)
            print a == asorted
            #print ' '.join(res)
seasor()

