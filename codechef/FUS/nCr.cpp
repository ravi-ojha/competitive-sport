#include <bits/stdc++.h>

using namespace std;

long long MOD = 1000000007;
long long nCr[1001][1001];

int main()
{
	for(int i=0;i<1001;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(i==j || j==0)
			{
				nCr[i][j] = 1;
			}
			else
			{
				nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
			}
		}
	}
	for(int i=0;i<11;i++)
	{
		printf("%lld\n",nCr[11][i]);
	}
	return 0;
}
