def toAndFro():
    t = input()
    while(t):
        s = raw_input()
        l = len(s)
        a = []
        b = []
        i = 0
        k = 0
        while i<l:
            if k&1:
                temp = s[i:i+t]
                temp = temp[::-1]
                a.append(temp)
            else:
                a.append(s[i:i+t])
            k += 1
            i += t
        #print a
        for i in xrange(t):
            for j in xrange(len(a)):
                b.append(a[j][i])
        print ''.join(b)
        t = input()
toAndFro()
