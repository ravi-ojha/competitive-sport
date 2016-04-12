#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	string t;
	cin >> s;
	cin >> t;
	int slen = s.length();
	int tlen = t.length();
	int i=0;
	while(s[i] == t[i])
	{
		i++;
	}
	string r = s;
	int flag = 0;
	while(i < slen)
	{
		if(r[i] == 'z')
		{
			i++;
			continue;
		}
		else
		{
			r[i]++;
			if(r > s && r < t)
			{
				cout << r << endl;
				flag = 1;
				break;
			}
			else
			{
				r[i]--;
			}
			i++;
		}
	}
	if(flag == 0)
	{
		cout << "No such string" << endl;
	}
	return 0;
}
