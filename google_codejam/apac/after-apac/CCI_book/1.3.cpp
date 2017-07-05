#include<bits/stdc++.h>
using namespace std;
/*
We maintain a frequency array which keeps track of occurences of characters in str1
Now when we traverse str2 we decrement the frequency array for that particular character
Now if both the strings were actually permutations of each other then, all the indices of frequency array should be 0
If not then strings were not permutations of each other
Else they are
*/
bool are_anagrams(string str1, string str2)
{
	int freq[256];
	memset(freq,0,sizeof(freq));
	int str1_len = str1.length();
	int str2_len = str2.length();
	for(int i=0;i<str1_len;i++)
	{
		freq[str1[i]]++;
	}
	for(int i=0;i<str2_len;i++)
	{
		freq[str2[i]]--;
	}
	for(int i=0;i<256;i++)
	{
		if(freq[i] != 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cout << are_anagrams("eminem","eeimmn") << endl;
	cout << are_anagrams("emi nem","eeimmn") << endl;
	cout << are_anagrams("eminem","eeimn") << endl;
	return 0;
}
