#include<iostream>
#include<cstdio>
using namespace std;
int dfs(char grid[510][510],int sx,int sy,int ex,int ey,int vis[510][510],int m,int n)
{
    if(sx > m || sy > n || sx <= 0 || sy <= 0)
    {
        return 0;
    }
    if(vis[sx][sy] == 2)
    {
        return 0;
    }
    //vis[sx][sy] = 1;
    if(sx == ex && sy == ey)
    {
        if(grid[sx][sy] == '.')
        {
            vis[sx][sy] = 2;
            return 1;
        }
        if(vis[sx][sy] == 0 && grid[sx][sy] == '*')
        {
            vis[sx][sy] = 1;
            grid[sx][sy] = '.';
            return 0;
        }
        if(vis[sx][sy] >= 1 && grid[sx][sy] == '.')
        return 1;
    }
    if(vis[sx][sy] == 0 && grid[sx][sy] == '*')
    {
        vis[sx][sy] = 1;
        grid[sx][sy] = '.';
        return 0;
    }
    if(vis[sx][sy] == 0 && grid[sx][sy] == '.')
    {
        //grid[sx][sy] = '.';
        vis[sx][sy] = 2;
        //return 0;
    }
    if(vis[sx][sy] == 1 && grid[sx][sy] == '.')
    {
        //grid[sx][sy] = '.';
        vis[sx][sy] = 2;
        //return 0;
    }
    int z = (dfs(grid,sx+1,sy,ex,ey,vis,m,n) ||
    dfs(grid,sx,sy+1,ex,ey,vis,m,n) ||
    dfs(grid,sx-1,sy,ex,ey,vis,m,n) ||
    dfs(grid,sx,sy-1,ex,ey,vis,m,n));
    //vis[sx][sy] = 0;
    return z;
}
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int m,n,i,j;
        scanf(" %d %d",&m,&n);
        char grid[510][510];
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf(" %c",&grid[i][j]);
            }
        }
        int sx,sy,ex,ey;
        scanf(" %d %d %d %d",&sx,&sy,&ex,&ey);
        int vis[510][510] = {0};
        int x;
        x = dfs(grid,sx,sy,ex,ey,vis,m,n);
        if(x)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
