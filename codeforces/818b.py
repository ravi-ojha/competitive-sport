def solve():
    n, m = map(int, raw_input().split())
    l = map(int, raw_input().split())
    res = [-1]*n

    llen = len(l)

    for i in xrange(llen-1):
        x = l[i]
        y = l[i+1]
        if y <= x:
            y = y+n

        res[x-1] = y-x

    rlen = len(res)
    for i in xrange(rlen):
        if res[i] == -1:
            res[i] = i+1

    print res
    if len(set(res)) == len(res):
        print ' '.join(str(i) for i in res)
    else:
        print -1

solve()
