#include <bits/stdc++.h>
using namespace std;
int main()
{
	while(true)
	{
		int a,b,c;
		scanf(" %d %d %d",&a,&b,&c);
		if(a == 0 && b == 0 && c == 0)
		{
			return 0;
		}
		else
		{
			int d1, d2, r1, r2;
			d1 = b - a;
			d2 = c - b;
			if(d1 == d2)
			{
				printf("AP %d\n",c+d1);
			}
			else
			{
				printf("GP %d\n",c*(b/a));
			}
		}
	}
}
