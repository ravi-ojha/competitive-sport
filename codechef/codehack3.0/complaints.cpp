#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n;
		scanf(" %d",&n);
		long long a[n];
		for(int i=0;i<n;i++)
		{
			scanf(" %lld",&a[i]);
		}
		long long res = 0;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(a[j]>a[i])
				{
					res++;
				}
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
