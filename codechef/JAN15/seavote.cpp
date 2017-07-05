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
		int b[n];
		int s = 0;
		int c0=0;
		for(int i=0;i<n;i++)
		{
			scanf(" %d",&b[i]);
			s += b[i];
			if(b[i] == 0)
			{
				c0++;
			}
		}
		if(s < 100)
		{
			printf("NO");
		}
		else
		{
			s -= 100;
			if(s<(n-c0))
			{
				printf("YES");
			}
			else
			{
				printf("NO");
			}
		}
		printf("\n");
	}
	return 0;
}
