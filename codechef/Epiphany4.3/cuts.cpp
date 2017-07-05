#include <bits/stdc++.h>
using namespace std;
long long a[11111111];
int main()
{
	a[0] = 1;
	int k = 0;
	long long i = 2;
	long long j = 1;
	while(a[k] < 1000000000000)
	{
		k++;
		a[k] = i*j;
		if(i>j)
		{
			j++;
		}
		else
		{
			i++;
		}
	}
	/*printf("k=%d\n",k);
	for(int i=0;i<20;i++)
	{
		printf(" %lld\n",a[i]);
	}*/
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		long long n;
		scanf(" %lld",&n);
		int res = 0;
		while(a[res] < n)
		{
			res++;
		}
		printf("%d\n",res);
	}
	return 0;
}
