#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n,m;
		scanf(" %d %d",&n,&m);
		double res = (double)n + (double)m - (double)1;
		printf("%.7lf\n",res);
	}
	return 0;
}
