#include <bits/stdc++.h>
using namespace std;
long long fact[10000001];
int main()
{
	fact[0] = 1;
	int n;
	scanf(" %d",&n);
	long long m;
	scanf(" %lld",&m);
	long long final = 0;
	fact[0] = fact[0]%m;
	for(int i=1;i<10000001;i++)
	{
		fact[i] = (i*fact[i-1])%m;
	}

	//Formula turns out to be (p+1)! - 1 + p*(p*(p+1))/2
	for(int i=0;i<n;i++)
	{
		long long p;
		scanf(" %lld",&p);
		long long first = 0;
		if((p+1)>=m)
		{
			first = -1 + m;
		}
		else
		{
			first = fact[p+1] - 1;
			first += m;
			first %= m;
		}

		long long second = 0;
		if(p&1)
		{
			second = (p+1)/2;
			second = ((second%m)*(p%m))%m;
		}
		else
		{
			second = p/2;
			second = ((second%m)*((p+1)%m))%m;
		}
		second = (second*(p%m))%m;
		final = (final + (first + second)%m)%m;
	}
	printf("%lld\n",final);
	return 0;
}
