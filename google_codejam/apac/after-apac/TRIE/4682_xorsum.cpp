#include <cstdio>
#include <iostream>
#include <algorithm>
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
		long long curr_max = a[0];
		long long max_so_far = a[0];
		for(int i=1;i<n;i++)
		{
			curr_max = max(a[i],a[i]^curr_max);
			max_so_far = max(max_so_far,curr_max);
		}
		printf("%lld\n",max_so_far);
	}
	return 0;
}
