#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k=0,n,l=1;
	string s;
	char d[10000];
	cin >> n;
	if(n<26)
	{
		cout << "NO" << endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		char t;
		cin >> t;
		if(t-64 >= 1 && t-64 <= 26){t = t-64+96;}
		d[i] = t;
	}
	sort(d+1,d+n+1);
	for(int i=1; i<=n;i++)
	{
		if(d[i]-96 == l)
		{
			l++;
			k++;
		}
	}
	if(k >= 26)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
