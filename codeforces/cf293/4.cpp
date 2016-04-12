#include <bits/stdc++.h>
using namespace std;
double res[2111][2111];
int main()
{
	int n,t;
	double p;
	scanf(" %d %lf %d",&n,&p,&t);
	res[0][0] = 1.0;
	for(int i=1;i<=t;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j==0)
			{
				res[i][j] = (1.0-p)*(res[i-1][j]);
			}
			else if(j==n)
			{
				res[i][j] = p*(res[i-1][j-1]);
			}
			else
			{
				res[i][j] = p*(res[i-1][j-1]) + (1.0-p)*(res[i-1][j]);
			}
			printf(" %.6lf",res[i][j]);
		}
		printf("\n");
	}
	printf(" %.6lf",res[t][n]);
	return 0;
}
