import sys
sys.setrecursionlimit(1000000)

pic_counter = 0
idx = 0
grid = []
vis = [[0]*1010 for x in xrange(1010)]
res = [[0]*1010 for x in xrange(1010)]
n,m = 0,0

# Total possible components
final_res = [0]*1000100

def dfs(x, y):
    global pic_counter, idx, grid, vis, res, n, m, final_res
    if(x < 0 or y < 0 or x >= n or y >= m):
        return
    if(vis[x][y]):
        return
    if(grid[x][y] == '*'):
        pic_counter += 1
        return
    vis[x][y] = 1
    dfs(x+1, y)
    dfs(x, y+1)
    dfs(x-1, y)
    dfs(x, y-1)
    res[x][y] = idx

def magic():
    global pic_counter, idx, grid, vis, res, n, m, final_res
    n,m,k = map(int, raw_input().split())
    for i in xrange(n):
        tmp = list(raw_input())
        grid.append(tmp)

    for _ in xrange(k):
        x,y = map(int,raw_input().split())
        x -= 1
        y -= 1
        if not vis[x][y]:
            idx += 1
            pic_counter = 0
            dfs(x, y)
            final_res[idx] = pic_counter
        print final_res[res[x][y]]
magic()
