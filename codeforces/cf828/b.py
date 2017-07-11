def solve():
    n, m = map(int, raw_input().split())
    grid = []
    for i in xrange(n):
        tmp = list(raw_input())
        grid.append(tmp)

    bcount = 0
    for i in xrange(n):
        for j in xrange(m):
            if grid[i][j] == 'B':
                bcount += 1

    # Agar, koi black hai hi nahi to bas 1 black box kaafi hai
    if bcount == 0:
        print '1'
    else:

        # for i in grid:
        #     print i

        a = 10000
        b = -1
        c = 10000
        d = -1

        for i in xrange(n):
            for j in xrange(m):
                if grid[i][j] == 'B':
                    a = min(a, i)
                    b = max(b, i)
                    c = min(c, j)
                    d = max(d, j)

        # print a, b, c, d


        # Max of height and width
        w = max(b-a+1, d-c+1)


        if (b-a+1) < w:
            while(a > 0 and (b-a+1) != w):
                a -= 1
            if (b-a+1) < w:
                while(b < m-1 and (b-a+1) != w):
                    b += 1

        elif (d-c+1) < w:
            while(c > 0 and (d-c+1) != w):
                c -= 1
            if (d-c+1) < w:
                while(d < n-1 and (d-c+1) != w):
                    d += 1

        # print a, b, c, d
        res = 0
        for i in xrange(a, b+1):
            for j in xrange(c, d+1):
                if i >= 0 and i < n and j >= 0 and j < m and grid[i][j] == 'W':
                    res += 1
                    grid[i][j] = 'B'


        bcount = 0
        for i in xrange(n):
            for j in xrange(m):
                if grid[i][j] == 'B':
                    bcount += 1


        # for i in grid:
        #     print i
        if bcount != w*w:
            print '-1'
        else:
            print res

solve()


