def solve():
    m, b = map(int, raw_input().split())
    res = 0

    for i in xrange(0, b+1):
        y = i
        x = (b - y)*m

        # print x, y

        n = x
        tmp = (n*(n+1))/2
        tmp = tmp*(y+1)

        n2 = y
        tmp2 = (n2*(n2+1))/2
        tmp2 = tmp2*(x+1)

        # print tmp, tmp2


        res = max(res, (tmp+tmp2))

    print res
solve()
