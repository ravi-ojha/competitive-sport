#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		char a[100001];
		scanf(" %s",a);
		int bal = 0;
		int mbal = 0;
		int alen = strlen(a);
		for(int i=0;i<alen;i++)
		{
			if(a[i] == '(')
			{
				bal++;
			}
			if(a[i] == ')')
			{
				bal--;
			}
			if(bal > mbal)
			{
				mbal = bal;
			}
		}
		//printf("%d\n",mbal);
		for(int i=0;i<mbal;i++)
		{
			printf("(");
		}
		for(int i=0;i<mbal;i++)
		{
			printf(")");
		}
		printf("\n");
	}
	return 0;
}
