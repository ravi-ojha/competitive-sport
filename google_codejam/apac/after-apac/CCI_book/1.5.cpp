#include <bits/stdc++.h>
using namespace std;

string compress_string(string str)
{
	string new_str = "";
	int str_len = str.length();
	char first;
	int i=0;
	int j=0;
	while(i<str_len)
	{
		first = str[i];
		int count = 0;
		while(i < str_len && str[i] == first)
		{
			i++;
			count++;
		}
		new_str.push_back(first);
		stringstream ss;  //now count can be 12 or 100 i.e. 2 digit number or 3 or more
		ss << count; // so we first convert it into string
		new_str.append(ss.str()); // and then append it to the new string
	}
	int new_str_len = new_str.length();
	if(new_str_len < str_len)
	{
		return new_str;
	}
	else
	{
		return str;
	}
}

int main()
{
	cout << compress_string("aabcccccaaa") << endl;
	cout << compress_string("aabc") << endl;
	return 0;
}
