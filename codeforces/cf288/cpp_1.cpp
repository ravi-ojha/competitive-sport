#include <bits/stdc++.h>
#define N 1011
using namespace std;
int main()
{
	int n, m, k;
	scanf(" %d %d %d",&n,&m,&k);
	int a[1011][1011];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			a[i][j] = 0;
		}
	}
	int x[100011];
	int y[100011];
	for(int i=1;i<=k;i++)
	{
		scanf(" %d %d",&x[i],&y[i]);
	}
	int res = 0;
	for(int i=1;i<=k;i++)
	{
		a[x[i]][y[i]] = 1;
		if(a[x[i]][y[i]+1] == 1 && a[x[i]+1][y[i]] == 1 && a[x[i]+1][y[i]+1] == 1)
		{
			res = i;
			break;
		}
		if(a[x[i]][y[i]-1] == 1 && a[x[i]+1][y[i]] == 1 && a[x[i]+1][y[i]-1] == 1)
		{
			res = i;
			break;
		}
		if(a[x[i]-1][y[i]] == 1 && a[x[i]-1][y[i]+1] == 1 && a[x[i]][y[i]+1] == 1)
		{
			res = i;
			break;
		}
		if(a[x[i]-1][y[i]-1] == 1 && a[x[i]-1][y[i]] == 1 && a[x[i]][y[i]-1] == 1)
		{
			res = i;
			break;
		}
	}
	printf("%d\n",res);
	return 0;
}
