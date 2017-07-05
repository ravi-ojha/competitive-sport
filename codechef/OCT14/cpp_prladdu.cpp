#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n;
		int a[100011];
		int i;
		scanf(" %d",&n);
		long long rsum = 0, res = 0;
		for(i=0;i<n;i++)
		{
			scanf(" %d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			rsum += a[i];
			if(rsum>0)
			{
				res += rsum;
			}
			else
			{
				res -= rsum;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
