#include <bits/stdc++.h>
using namespace std;

//we are given isSubSring function, we can call it only once
bool is_rotation(string str1, string str2)
{
	int str1_len = str1.length();
	str1.append(str1);
	if(isSubString(str1,str2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	return 0;
}
