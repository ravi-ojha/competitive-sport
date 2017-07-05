#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n,m;
		scanf(" %d %d",&n,&m);
		double a[1001][1001];
		double res = 0.0;
		a[0][0] = 1.0;
		for(int i=1;i<m;i++)
		{
			a[0][i] = a[0][i-1]/(double)2;
		}
		for(int i=1;i<n;i++)
		{
			a[i][0] = a[i-1][0]/(double)2;
		}
		for(int i=1;i<(n-1);i++)
		{
			for(int j=1;j<(m-1);j++)
			{
				a[i][j] = a[i-1][j]/(double)2 + a[i][j-1]/(double)2;
			}
		}

		for(int i=1;i<(m-1);i++)
		{
			a[n-1][i] = a[n-1][i-1] + a[n-2][i]/(double)2;
		}

		for(int i=1;i<(n-1);i++)
		{
			a[i][m-1] = a[i-1][m-1] + a[i][m-2]/(double)2;
		}
		a[n-1][m-1] = 1.0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				//printf(" %f",a[i][j]);
				res += a[i][j];
			}
			printf("\n");
		}
		printf("%.7lf\n",res);
	}
	return 0;
}
