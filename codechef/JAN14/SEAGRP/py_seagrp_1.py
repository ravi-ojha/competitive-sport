vis = [0]*110
grid = []
for i in xrange(110):
    grid.append([0]*110)
from sys import stdin
def dfs(n,c):
    if c == 0:
        return True
    for i in xrange(n):
        if vis[i] == 0:
            for j in xrange(n):
                if vis[j] == 0 and grid[i][j] == 1:
                    vis[j] = 1
                    vis[i] = 1
                    if dfs(n,c-2):
                        return True
                    vis[j] = 0
                    vis[i] = 0
            if j == (n-1):
                return False
    return False

def seagrp():
    data = (line for line in stdin.read().splitlines())
    for t in xrange(int(next(data))):
        n,m = map(int,next(data).split())
        for i in xrange(110):
            vis[i] = 0
            for j in xrange(110):
                grid[i][j] = 0
        for i in xrange(m):
            x,y = map(int,next(data).split())
            x -= 1
            y -= 1
            grid[x][y] = 1
            grid[y][x] = 1
        if n%2 == 1:
            print 'NO'
        else:
            if dfs(n,n):
                print 'YES'
            else:
                print 'NO'
seagrp()
