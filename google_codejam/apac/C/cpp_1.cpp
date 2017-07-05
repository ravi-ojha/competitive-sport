#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
int mark[400][400] = {0};
int mines[400][400] = {0};
void mark_recur(int i,int j)
{
	if(mark[i-1][j-1] == 0)
	{
		mark[i-1][j-1] = 1;
		if(mines[i-1][j-1] == 0)
		{
			mark_recur(i-1,j-1);
		}
	}
	if(mark[i-1][j] == 0)
	{
		mark[i-1][j] = 1;
		if(mines[i-1][j] == 0)
		{
			mark_recur(i-1,j);
		}
	}
	if(mark[i-1][j+1] == 0)
	{
		mark[i-1][j+1] = 1;
		if(mines[i-1][j+1] == 0)
		{
			mark_recur(i-1,j+1);
		}
	}
	if(mark[i][j-1] == 0)
	{
		mark[i][j-1] = 1;
		if(mines[i][j-1] == 0)
		{
			mark_recur(i,j-1);
		}
	}
	if(mark[i][j+1] == 0)
	{
		mark[i][j+1] = 1;
		if(mines[i][j+1] == 0)
		{
			mark_recur(i,j+1);
		}
	}
	if(mark[i+1][j-1] == 0)
	{
		mark[i+1][j-1] = 1;
		if(mines[i+1][j-1] == 0)
		{
			mark_recur(i+1,j-1);
		}
	}
	if(mark[i+1][j] == 0)
	{
		mark[i+1][j] = 1;
		if(mines[i+1][j] == 0)
		{
			mark_recur(i+1,j);
		}
	}
	if(mark[i+1][j+1] == 0)
	{
		mark[i+1][j+1] = 1;
		if(mines[i+1][j+1] == 0)
		{
			mark_recur(i+1,j+1);
		}
	}
	return;
}
int main()
{
	int t;
	scanf(" %d",&t);
	int tt;
	for(tt=1;tt<=t;tt++)
	{
		int n,i,j;
		scanf(" %d",&n);
		char grid[400][400];
		for(i=0;i<n;i++)
		{
			scanf(" %s",grid[i]);
		}
		char newgrid[400][400] = {0};
		for(i=0;i<400;i++)
		{
			for(j=0;j<400;j++)
			{
				newgrid[i][j] = '#';
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				newgrid[i][j] = grid[i-1][j-1];
			}
		}

		/*for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				printf(" %c",newgrid[i][j]);
			}
			printf("\n");
		}*/
		for(i=0;i<400;i++)
		{
			for(j=0;j<400;j++)
			{
				mines[i][j] = -1;
				mark[i][j] = 0;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(newgrid[i][j] != '*')
				{
					int c = 0;
					if(newgrid[i-1][j-1] == '*')
					{
						c++;
					}
					if(newgrid[i-1][j] == '*')
					{
						c++;
					}
					if(newgrid[i-1][j+1] == '*')
					{
						c++;
					}
					if(newgrid[i][j-1] == '*')
					{
						c++;
					}
					if(newgrid[i][j+1] == '*')
					{
						c++;
					}
					if(newgrid[i+1][j-1] == '*')
					{
						c++;
					}
					if(newgrid[i+1][j] == '*')
					{
						c++;
					}
					if(newgrid[i+1][j+1] == '*')
					{
						c++;
					}
					mines[i][j] = c;
				}
				else
				{
					mines[i][j] = -1;
				}
			}
		}
		/*for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				printf(" %d",mines[i][j]);
			}
			printf("\n");
		}*/
		int res = 0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(mark[i][j] == 0 && mines[i][j] != -1)
				{
					if(mines[i][j] == 0)
					{
						mark[i][j] = 1;
						res++;
						mark_recur(i,j);
					}
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(mark[i][j] == 0 && mines[i][j] != -1)
				{
					res++;
				}
			}
		}
		printf("Case #%d: %d\n",tt,res);
	}
	return 0;
}
