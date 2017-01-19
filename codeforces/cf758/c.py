n,m,k,x,y = map(int, raw_input().split())

a = []
for i in xrange(110):
    a.append([0]*110)


if n == 1:
    pupils = m
    avg = k/pupils
    for j in xrange(1, m+1):
        a[1][j] += avg
        k -= avg

    j = 1
    while(k > 0):
        a[1][j] += 1
        k -= 1
        j += 1
        if(j > m):
            j = 1
else:

    # For first row
    for j in xrange(1, m+1):
        a[1][j] = 1
        k -= 1

    # Effective number of pupils for dumb teacher
    pupils = m*(n-1)

    f = 1

    if k < pupils:
        f = 0

    # for pupils not in first and last row
    avg = k/pupils

    # For pupils in first and last row
    avg_half = avg/2

    # Exclude first and last row
    for i in xrange(2, n):
        for j in xrange(1, m+1):
            a[i][j] += avg
            k = k - avg

    # For first row
    for j in xrange(1, m+1):
        a[1][j] += avg_half
        k = k - avg_half

    # For last row
    for j in xrange(1, m+1):
        a[n][j] += avg_half
        k = k - avg_half

    # for i in xrange(1, n+1):
    #     for j in xrange(1, m+1):
    #         print a[i][j],
    #     print


    if f == 0:
        i = 2
    else:
        i = n
    j = 1
    while(k > 0):
        a[i][j] += 1
        j += 1
        if(j > m):
            j = 1
            if(f == 0):
                i += 1
                if(i > n):
                    i = n-1
                    f = 1
            else:
                i -= 1
                if(i <= 0):
                    i = 2
                    f = 0
        k -= 1          

maxi = a[1][1]
mini = a[1][1]
for i in xrange(1, n+1):
    for j in xrange(1, m+1):
        maxi = max(maxi, a[i][j])
        mini = min(mini, a[i][j])

for i in xrange(1, n+1):
    for j in xrange(1, m+1):
        print a[i][j],
    print

print maxi, mini, a[x][y]
