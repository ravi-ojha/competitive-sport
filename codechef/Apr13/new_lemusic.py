def lemusic():
    t = input()
    for e in range(t):
        le = []
        ne = []
        ans = 0
        tr = []
        n = input()
        for f in range(n):
            w = map(int,raw_input().split())
            #w.append(w[0]*1000000000 + w[1])
            #w.append(1)
            le.append(w)
        #print le
        le.sort()
        #print le
        z = le[0][0]
        j = 1
        #ans = ans + le[0][1]
        ne.append(le[0][1])
        f = 0
        while f<n:
            while f<n and le[f][0] == z:
                tr.append(le[f][1])
                #le[f][2] = 0
                f += 1
            if f>= n:
                break
            j += 1
            z = le[f][0]
            #ans = ans + j*le[f][1]
            ne.append(le[f][1])
            f += 1
        #print j
        #print ne
        ne.sort()
        #print ne
        for k in range(j):
            ans = ans + (k+1)*ne[k]
        #print ans
        #print tr
        #for k in range(1,n):
            #if le[k][2] == 0:
                #ans = ans + j*le[k][1]
        for k in range(1,len(tr)):
            ans = ans + j*tr[k]
        print ans
lemusic()