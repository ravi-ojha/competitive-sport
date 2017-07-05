#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		long long res = 0;
		long long b;
		scanf(" %lld",&b);
		if(b&1)
		{
			b--;
		}
		b = b-2;
		b = b/2;
		res = b*(b+1);
		res = res/2;
		printf("%lld\n",res);
	}
	return 0;
}
