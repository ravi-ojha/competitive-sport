#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s,ans="",t;
	int a,b,i,j,x=0,y;
	cin >> s;
	t = s;
	for(i=0;i<s.size();i++)
	{
		a = s[i] - 48;
		if(a%2 == 0)
		{
			x = 1;
			swap(t[i],t[s.size()-1]);
			ans = max(ans,t);
			t = s;
		}
	}
	if(x==1) cout << ans;
	else cout << -1;
	return 0;
}
