#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int res = 0;
		int a[n];
		int b[n];
		for(int i=0;i<n;i++)
		{
			scanf(" %d",&a[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf(" %d",&b[i]);
		}
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0;i<n;i++)
		{
			res += a[i]*b[i];
		}
		printf("%d\n",res);
	}
	return 0;
}
