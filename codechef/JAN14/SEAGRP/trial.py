t = input()
for u in xrange(t):
    n,m = map(int,raw_input().split())
    a = [0]*n
    grid = []
    for i in xrange(n):
        x = [0]*n
        grid.append(x)
    for i in xrange(m):
        x,y = map(int,raw_input().split())
        x -= 1
        y -= 1
        if grid[x][y] == 0 or grid[y][x] == 0:
            a[x] += 1
            a[y] += 1
            grid[x][y] = 1
            grid[y][x] = 1
    #print a
    if n%2 == 1:
        print 'NO'
    else:
        if 0 in a:
            print 'NO'
        else:
            if sum(a)%2 == 0:
                print 'YES'
            else:
                print 'NO'
