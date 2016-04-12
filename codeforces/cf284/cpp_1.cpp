#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int main()
{
	int n, x;
	scanf(" %d %d",&n,&x);
	int curr = 1;
	int res = 0;
	int a,b;
	for(int i=0;i<n;i++)
	{
		scanf(" %d %d",&a,&b);
		res += (b-a+1);
		if((a-curr)/x > 0)
		{
			curr = curr + ((a-curr)/x)*x;
			res += (a-curr);
		}
		else
		{
			res +=(a-curr);
		}
		curr = b+1;
		//printf("%d\n",res);
	}
	printf("%d\n",res);
	return 0;
}
