#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1010][1010];

int main()
{
	int t;
	scanf(" %d",&t);
	int tt;
	for(tt=1;tt<=t;tt++)
	{
		vector < pair <int,int> > end_points;
		int i,j;
		int s;
		scanf(" %d",&s);

		for(i=0;i<(s+2);i++)
		{
			for(j=0;j<(s+2);j++)
			{
				a[i][j] = -1;
			}
		}
		for(i=1;i<=s;i++)
		{
			for(j=1;j<=s;j++)
			{
				scanf(" %d",&a[i][j]);
			}
		}
		for(i=1;i<=s;i++)
		{
			for(j=1;j<=s;j++)
			{
				int curr = a[i][j];
				if(curr == (a[i-1][j]-1) || curr == (a[i][j-1]-1) || curr == (a[i][j+1]-1) || curr == (a[i+1][j]-1))
				{
					continue;
				}
				else
				{
					end_points.push_back(make_pair(i,j));
				}
			}
		}
		int vlen = end_points.size();
		int rwin = 1111;
		int dwin = 0;
		for(i=0;i<vlen;i++)
		{
			//printf(" %d %d\n",end_points[i].first,end_points[i].second);
			int x = end_points[i].first;
			int y = end_points[i].second;
			int d = 1;
			while(1)
			{
				if(a[x][y] == (a[x-1][y]+1) || a[x][y] == (a[x][y-1]+1) || a[x][y] == (a[x][y+1]+1) || a[x][y] == (a[x+1][y]+1))
				{
					if(a[x][y] == (a[x-1][y]+1))
					{
						x = x-1;
					}
					else if(a[x][y] == (a[x][y-1]+1))
					{
						y = y-1;
					}
					else if(a[x][y] == (a[x][y+1]+1))
					{
						y = y+1;
					}
					else if(a[x][y] == (a[x+1][y]+1))
					{
						x = x+1;
					}
					d++;
				}
				else
				{
					if(d == dwin)
					{
						rwin = min(a[x][y],rwin);
					}
					if(d > dwin)
					{
						dwin = d;
						rwin = a[x][y];
					}

					break;
				}
			}
		}
		printf("Case #%d: %d %d\n",tt,rwin,dwin);
		end_points.clear();
	}
	return 0;
}
