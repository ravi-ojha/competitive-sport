#include <cstdio>
#include <iostream>
using namespace std;
int n;
int res;
int a[21][21];
int vis[21][21];
void dfs(int x, int y)
{
	if(x < 0 || y < 0 || x >= n || y >= n)
	{
		return;
	}
	if(x == n-1 && y == n-1)
	{
		res++;
		return;
	}
	if(a[x][y] == 1)
	{
		return;
	}
	if(vis[x][y])
	{
		return;
	}
	vis[x][y] = 1;
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
	vis[x][y] = 0;
}
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		res = 0;
		scanf(" %d",&n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf(" %d",&a[i][j]);
				vis[i][j] = 0;
			}
		}
		if(a[0][0] == 1 && a[n-1][n-1] == 1)
		{

		}
		else
		{
			a[0][0] = 0;
			//a[n-1][n-1] = 0;
			dfs(0,0);
		}
		printf("%d\n",res);
	}
	return 0;
}
