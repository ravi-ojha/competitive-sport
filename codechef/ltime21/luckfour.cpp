#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		string s;
		cin >> s;
		int count = 0;
		int slen = s.length();
		for(int i=0;i<slen;i++)
		{
			if(s[i] == '4')
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
