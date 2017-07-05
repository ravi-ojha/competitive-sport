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
		int s = 0;
		int x;
		for(int i=0;i<n;i++)
		{
			scanf(" %d",&x);
			s += x;
		}
		if(s%n == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
