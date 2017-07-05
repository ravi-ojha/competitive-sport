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
		int a[n];
		int freq[100001] = {0};
		for(int i=0;i<n;i++)
		{
			scanf(" %d",&a[i]);
			freq[a[i]]++;
		}
		int res = INT_MAX;
		for(int i=1;i<100001;i++)
		{
			res = min(res,n-freq[i]);
		}
		printf("%d\n",res);
	}
	return 0;
}
