#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n;
		scanf(" %d",&n);
		for(int i=0;i<n;i++)
		{
			int x,y;
			scanf(" %d %d",&x,&y);
		}
		int res = 1;
		for(int i=2;i<=n;i++)
		{
			res = res ^ i;
		}
		printf("%d\n",res);
	}
	return 0;
}
