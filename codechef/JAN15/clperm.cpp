#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		long long n,k,pre=0;
		scanf(" %lld %lld",&n,&k);
		long long a[k];
		//long long l[k];
		//memset(l,0,sizeof(l));
		for(int i=0;i<k;i++)
		{
			scanf(" %lld",&a[i]);
			//pre += a[i];
			//l[i] = pre;
		}
		sort(a,a+k);
		long long s;
		if(k != 0)
		{
			int flag = 1;
			for(int i=0;i<k;i++)
			{
				if(i)
				{
					s += ((a[i]-a[i-1]-1)*(a[i]+a[i-1]))/2;
				}
				else
				{
					s = (a[i]*(a[i]-1))/2;
				}
				if(s<a[i])
				{
					flag = 0;
					s = a[i];
					break;
				}
			}
			if(flag)
			{
				s += ((n-a[k-1])*(n+a[k-1]+1))/2;
				s++;
			}
			if(s&1)
			{
				printf("Chef\n");
			}
			else
			{
				printf("Mom\n");
			}
		}
		else
		{
			s = (n*(n+1))/2;
			s++;
			if(s&1)
			{
				printf("Chef\n");
			}
			else
			{
				printf("Mom\n");
			}
		}
	}
	return 0;
}
