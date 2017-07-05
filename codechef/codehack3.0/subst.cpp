#include <bits/stdc++.h>
using namespace std;
string make_string(string bad, int begin, int end)
{
	string tmp = "";
	for(int i=begin;i<end;i++)
	{
		tmp.push_back(bad[i]);
	}
	return tmp;
}
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		string good, bad;
		//scanf(" %s %s",good,bad);
		cin >> good;
		cin >> bad;
		int glen = good.length();
		int blen = bad.length();
		int res = INT_MAX;
		for(int i=0;(i+blen)<=glen;i++)
		{
			int tmp = 0;
			for(int j=0;j<blen;j++)
			{
				if(good[i+j] != bad[j])
				{
					tmp++;
				}
			}
			res = min(tmp,res);
		}
		printf("%d\n",res);
	}
	return 0;
}
