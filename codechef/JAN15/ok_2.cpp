#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n;
		scanf(" %d",&n);
		for(int i=0;i<100005;i++)
		{
			arr[i] = -1;
		}
		int a,b;
		vector < pair<int,int> > v;
		for(int i=0;i<n;i++)
		{
			scanf(" %d %d",&a,&b);
			v.push_back(make_pair(b,a));
		}
		sort(v.begin(), v.end());
		int res = 0;
		for(int i=0;i<n;i++)
		{
			if(arr[i] == 0)
			{
				continue;
			}
			for(int j=i+1;j<n;j++)
			{
				if(arr[j] == 0)
				{
					continue;
				}
				if(v[j].second <= v[i].first)
				{
					arr[j] = 0;
				}
			}
			res++;
		}
		printf("%d\n",res);
	}
	return 0;
}
