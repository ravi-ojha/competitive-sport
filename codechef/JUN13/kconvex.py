def convex():
    n,k = map(int,raw_input().split())
    a = map(int,raw_input().split())
    arr = []
    for i in xrange(n):
        arr.append([a[i],i])
    i = 0
    j = 0
    res1 = []
    count = 0
    a.sort()
    arr.sort(key = lambda x : x[0])
    
    while i<=(n-k):
        #print arr
        #print a
        if count == 2:
            break
        summ = sum(a[i:i+k])
        #print summ
        if all( 2*x < summ for x in a[i:i+k]):
            count += 1
            #print 'count' + str(count)
            if count == 1:
                for p in xrange(i,i+k):
                    res1.append(str(arr[i][1] + 1))
                    del arr[i]
                    del a[i]
            else:
                for p in xrange(i,i+k):
                    res1.append(str(arr[p][1] + 1))
            i = 0
            n = n-k
        else:
            i += 1
    if count == 2:
        print 'Yes'
        print " ".join(res1)
    else:
        print 'No'
convex()
