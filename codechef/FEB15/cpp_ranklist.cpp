#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n;
		long long s;
		scanf(" %d %lld",&n,&s);
		int a[100011];
		// Initialize the array
		for(int i=1;i<100001;i++)
		{
			a[i] = i;
		}
		long long nn = (long long)n;
		long long r = (nn*(nn+1))/2 - s;
		int i = n;
		//Move right to left in the array and try to make all a[i] = 1 as long as possible using r (remaining sum)
		while(i > 0 && (r-(a[i]-1)) >= 1)
		{
			r = r - (a[i] - 1);
			a[i] = 1;
			i--;
			//printf("%lld here\n",r);
		}
		int res = 0;
		if(i > 0 && i <= n)
			a[i] = a[i] - r;
		int freq[100011] = {0};
		//count repeating numbers, which is our answer
		for(int j=1;j<=n;j++)
		{
			if(freq[a[j]])
			{
				res++;
			}
			freq[a[j]]++;
		}
		printf("%d\n",res);
	}
	return 0;
}
