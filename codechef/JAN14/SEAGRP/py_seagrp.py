vis = [0]*110
grid = []
for i in xrange(110):
    grid.append([0]*110)

def dfs(n,c):
    if c == 0:
        #print 'oye'
        return True
    for i in xrange(n):
        if vis[i] == 0:
            for j in xrange(n):
                if vis[j] == 0 and grid[i][j] == 1:
                    vis[i] = 1
                    vis[j] = 1
                    if dfs(n,c-2):
                        return True
                    else:
                        vis[j] = 0
                        vis[i] = 0
            if j == (n-1):
            	#print 'hehe'
                return False
    #print 'sala'
    return False

def seagrp():
    for t in xrange(input()):
        n,m = map(int,raw_input().split())
        for i in xrange(110):
            vis[i] = 0
            for j in xrange(110):
                grid[i][j] = 0
        for i in xrange(m):
            x,y = map(int,raw_input().split())
            x -= 1
            y -= 1
            grid[x][y] = 1
            grid[y][x] = 1
        if dfs(n,n):
            print 'YES'
        else:
            print 'NO'
seagrp()
