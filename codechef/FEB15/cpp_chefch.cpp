#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		char s[100001];
		scanf(" %s",s);
		int m1=0, m2=0;
		int slen = strlen(s);

		//This loop is for s[0] = '-', so for all odd i, replace if its '-'
		//for all even i replace if its '+'
		for(int i=0;i<slen;i++)
		{
			if(i&1)
			{
				if(s[i] == '-')
				{
					m1++;
				}
			}
			else
			{
				if(s[i] == '+')
				{
					m1++;
				}
			}
		}
		//This loop is for s[0] = '+', so for all odd i, replace if its '+'
		//for all even i replace if its '-'
		for(int i=0;i<slen;i++)
		{
			if(i&1)
			{
				if(s[i] == '+')
				{
					m2++;
				}
			}
			else
			{
				if(s[i] == '-')
				{
					m2++;
				}
			}
		}
		printf("%d\n",min(m1,m2));
	}
	return 0;
}
