#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf(" %d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf(" %d",&a[i]);
	}
	int lis[n];
	for(int i=0;i<n;i++)
	{
		lis[i] = 1;
		for(int j=0; j<i; j++)
		{
			if(a[j] < a[i])
			{
				lis[i] = max(lis[i], lis[j]+1);			
			}
		}
	}
	int res = 0;
	for(int i=0;i<n;i++)
	{
		//printf(" %d",lis[i]);
		res = max(lis[i],res);
	}
	printf("%d\n",res);
	return 0;
}
