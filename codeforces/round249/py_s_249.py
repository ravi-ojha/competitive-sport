def s_249():
    a,k = map(int,raw_input().split())
    b = []
    n = len(str(a))
    if k >= (n*(n-1))/2:
        a = list(str(a))
        for i in a:
            b.append(int(i))
        b.sort()
        b.reverse()
        c = []
        for i in b:
            c.append(str(i))
        print ''.join(c)
    else:
        a = list(str(a))
        c = [0]*len(a)
        j = 0
        for i in a:
            b.append(int(i))
        while k > 0:
            i = b.index(max(b))
            if k >= i:
                c[j] = b[i]
                k = k - i
                del b[i]
                
                
s_249()
