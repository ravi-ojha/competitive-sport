def chode():
    for t in xrange(input()):
        h = raw_input()
        c = raw_input()
        clen = len(c)
        cc = c.lower()
        freq = []
        for i in xrange(26):
            freq.append([0,i+ord('a')])
        res = ['*']*clen
        for i in xrange(clen):
            z = ord(cc[i]) - ord('a')
            if z>=0 and z<26:
                freq[z][0] += 1
                res[i] = '8'
            else:
                res[i] = cc[i]
        #print res
        #print freq
        freq.sort()
        #print freq
        i = 25
        while i >= 0:
            x = chr(freq[i][1])
            y = h[i]
            for j in xrange(clen):
                if cc[j] == x:
                    res[j] = y
            i -= 1
        #print res
        for i in xrange(clen):
            if ord(c[i]) >= 65 and ord(c[i]) <= 90:
                res[i] = chr(ord(res[i]) - 32)
        print ''.join(res)
chode()
