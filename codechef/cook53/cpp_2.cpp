#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define MOD 10000007
using namespace std;

int main()
{
	int n,m;
	scanf(" %d %d",&n,&m);
	long long a[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf(" %lld",&a[i][j]);
			if(a[i][j] < 0)
			{
				a[i][j] += MOD;
			}
		}
	}
	long long dp[n][m];
	for(int i=0;i<n;i++)
	{
		dp[i][0] = a[i][0];
	}

	for(int i=0;i<m;i++)
	{
		long long tmp = 0;
		for(int j=0;j<n;j++)
		{
			tmp += dp[j][i];
			tmp %= MOD;
		}
		if(i+1 < m)
		{
			for(int j=0;j<n;j++)
			{
				dp[j][i+1] = a[j][i+1]*tmp;
				dp[j][i+1] %= MOD;
			}
		}
	}
	long long res = 0;
	for(int i=0;i<n;i++)
	{
		res += dp[i][m-1];
		res %= MOD;
	}
	printf("%lld\n",res);
	return 0;
}
