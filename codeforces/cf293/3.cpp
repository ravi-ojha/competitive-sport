#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;
	scanf(" %d %d %d",&n,&m,&k);
	int a[100011];
	int idx[100011];
	for(int i=1;i<=n;i++)
	{
		scanf(" %d",&a[i]);
		idx[a[i]] = i;
	}
	long long res = 0;
	for(int i=1;i<=m;i++)
	{
		int tmp;
		scanf(" %d",&tmp);
		int curridx = idx[tmp];
		if(curridx != 1)
		{
			int incre = (curridx-1)/k;
			res += incre;
			res++; //for press
			int currapp = a[curridx];
			int prevapp = a[curridx-1];
			int previdx = curridx-1;


			int swaptmmp = a[curridx];
			a[curridx] = a[curridx-1];
			a[curridx-1] = swaptmmp;

			idx[prevapp] = curridx;
			idx[currapp] = curridx-1;
			//cout << res << endl;
		}
		else
		{
			res++;
		}
	}
	cout << res << endl;
	return 0;
}
