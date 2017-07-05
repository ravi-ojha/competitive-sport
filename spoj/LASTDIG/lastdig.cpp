#include <bits/stdc++.h>
using namespace std;
long long fast_pow(long long a, long long n, long long m)
{
	long long res = 1;
	while(n>0)
	{
		if(n&1)
		{
			res = res*a;
			res %= m;
		}
		a = a*a;
		a %= m;
		n = n >> 1;
	}
	return res;
}
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		long long a,b;
		scanf(" %lld %lld",&a,&b);
		printf("%lld\n",fast_pow(a,b,10));
	}
	return 0;
}
