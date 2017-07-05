#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	int tt;
	for(tt=1;tt<=t;tt++)
	{
		int n,i,j;
		scanf(" %d",&n);
		int src[511];
		int dst[511];
		for(i=0;i<n;i++)
		{
			scanf(" %d %d",&src[i],&dst[i]);
		}
		int city[5111] = {0};
		for(i=1;i<=5000;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i >= src[j] && i <= dst[j])
				{
					city[i]++;
				}
			}
		}
		int p;
		scanf(" %d",&p);
		printf("Case #%d:",tt);
		while(p--)
		{
			int q;
			scanf(" %d",&q);
			printf(" %d",city[q]);
		}
		printf("\n");
	}
	return 0;
}
