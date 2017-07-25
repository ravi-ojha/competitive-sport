def solve():
    n, p, q = map(int, raw_input().split())
    s = raw_input()

    x = -1
    y = -1

    for i in xrange(0, 101):
        for j in xrange(0, 101):
            if p*i + q*j == n:
                x = i
                y = j

    if x == -1:
        print x
    else:
        res = []
        j = 0
        for i in xrange(x):
            res.append(s[j:j+p])
            j = j+p
        for i in xrange(y):
            res.append(s[j:j+q])
            j = j+q

        print len(res)
        for i in res:
            print i
solve()
