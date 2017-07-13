def solve():
    s1 = raw_input()
    s2 = raw_input()

    d = {}

    i = 0
    while i < 26:
        d[s1[i]] = s2[i]
        i += 1

    i = 0
    while i < 26:
        x = s1[i]
        y = s2[i]
        d[x.upper()] = y.upper()
        i += 1

    q = raw_input()
    res = []
    for i in q:
        if i in d:
            res.append(d[i])
        else:
            res.append(i)

    print ''.join(res)

solve()
