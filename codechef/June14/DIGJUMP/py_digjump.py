def digjump():
    s = list(raw_input())
    slen = len(s)
    first = [9999999]*11
    last = [-1]*11
    r = []
    for i in xrange(slen):
        r.append(int(s[i]))
        first[r[i]] = min(i,first[r[i]])
        last[r[i]] = max(i,last[r[i]])
    print first
    print last
#digjump()

def digjump2():
    s = list(raw_input())
    slen = len(s)
    r = []
    used = [-1]*10
    for i in xrange(slen):
        r.append(int(s[i]))
    i = slen - 1
    f = [0]*slen
    z = 0
    while i >= 0:
        if used[r[i]] >= 0:
            f[i] = f[used[r[i]]] + 1
        else:
            used[r[i]] = i
            f[i] = z
            z += 1
        i -= 1
    print f[0]
    print f
#digjump2()

def digjump3():
    s = list(raw_input())
    slen = len(s)
    for i in xrange(slen):
        s[i] = int(s[i])
    f = [0]*slen
    ranges = []
    for i in xrange(slen):
        if s[i] == s[slen-1]:
            ranges.append(i)
            f[i] = 0
        i += 1
    rlen = len(ranges)
    i = 0
    print ranges
    print f
    while i < (rlen-1):
        z = 0
        mid = (ranges[i] + ranges[i+1])
        if mid%2 == 0:
            mid = mid/2
            for j in xrange(ranges[i],mid+1):
                f[j] = z
                z += 1
            z -= 1
            for j in xrange(mid,ranges[i+1]):
                f[j] = z
                z -= 1
        else:
            mid = mid/2
            for j in xrange(ranges[i],mid+1):
                f[j] = z
                z += 1
            z -= 1
            for j in xrange(mid+1,ranges[i+1]):
                f[j] = z
                z -= 1
        i += 1
    j = ranges[0]
    z = 0
    while j >= 0:
        f[j] = z
        z += 1
        j -= 1
    print s
    print f
    r = [99999999]*10
    for i in xrange(slen):
        r[s[i]] = min(r[s[i]],f[i])
    print r
    for i in xrange(slen):
        f[i] = r[s[i]]
    for i in xrange(1,slen-1):
        f[i] = min(f[i],min(f[i-1],f[i+1]) + 1)
    f[0] = min(f[0],f[1]+1)
    f[slen-1] = min(f[slen-1],f[slen-2]+1)
    i = slen-2
    while i > 0:
        f[i] = min(f[i],min(f[i-1],f[i+1]) + 1)
        i -= 1
    f[0] = min(f[0],f[1]+1)
    f[slen-1] = min(f[slen-1],f[slen-2]+1)
    print f
    for i in xrange(slen):
        r[s[i]] = min(r[s[i]],f[i])
    print r
    print r[s[0]] + 1
digjump3()
