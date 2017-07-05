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
		float res = 0.0;
		for(int i=1;i<=n;i++)
		{
			res = res + float(1)/float(i);
		}
		res = res*n;
		printf("%f\n",res);
	}
	return 0;
}
