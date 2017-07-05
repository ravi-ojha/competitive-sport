#include <bits/stdc++.h>
using namespace std;
class DecipherabilityEasy
{
public:
	string check(string s, string t)
	{
		string yes = "Possible";
		string no = "Impossible";
		int f1[256] = {0};
		int f2[256] = {0};
		int slen = s.length();
		int tlen = t.length();
		for(int i=0;i<slen;i++)
		{
			f1[s[i]]++;
		}
		for(int i=0;i<tlen;i++)
		{
			f2[t[i]]++;
		}
		int flag = 0;
		int diff;
		for(int i=97;i<=122;i++)
		{
			if(f1[i] != f2[i])
			{
				flag++;
				diff = f1[i] - f2[i];
			}
		}
		if(flag == 1)
		{
			if(diff == 1)
			{
				return yes;
			}
			else
			{
				return no;
			}
		}
		else
		{
			return no;
		}
		return 0;
	}
};

int main()
{
	DecipherabilityEasy ob;

}
