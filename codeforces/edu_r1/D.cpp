#include <bits/stdc++.h>
using namespace std;
int n,m,k;
char grid[1010][1010];
int vis[1010][1010] = {0};
int tmp_res[1010][1010] = {0};
int cnt = 0;
int final_res[10001000] = {0};
int idx = 0; // idx for compoenent_map

void dfs(int x,int y)
{
    if(x < 0 || y < 0 || x >= n || y >= m)
    {
        return;
    }
    if(vis[x][y])
    {
        return;
    }
    if(grid[x][y] == '*')
    {
        cnt++;
        return;
    }
    vis[x][y] = 1;
    dfs(x+1, y);
    dfs(x, y+1);
    dfs(x-1, y);
    dfs(x, y-1);
    tmp_res[x][y] = idx;
}

int main()
{
    scanf(" %d %d %d", &n,&m,&k);
    for(int i=0;i<n;i++)
    {
        scanf(" %s", grid[i]);
    }
    for(int i=0;i<k;i++)
    {
        int x,y;
        scanf(" %d %d",&x,&y);
        x--;
        y--;
        if(!vis[x][y])
        {
            idx++;
            cnt = 0;
            dfs(x,y);
            final_res[idx] = cnt;
        }
        printf("%d\n",final_res[tmp_res[x][y]]);
    }
}