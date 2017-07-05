#include <bits/stdc++.h>
using namespace std;

/*This method requires extra space to store if a character
was previously encountered or not*/

bool all_unique_chars(string str)
{
	bool exists[256]; //assuming we are dealing with only ASCII characters
	memset(exists,0,sizeof(exists));
	int str_len = str.length();
	for(int i=0;i<str_len;i++)
	{
		if(exists[str[i]])
		{
			return false;
		}
		exists[str[i]] = 1;
	}
	return true;
}

/*Following method efficiently uses the extra space by working at
bit level to store if a character was previously encountered or not*/

bool all_unique_chars_2(string str)
{
	int exists[8]; // each int can hold 32 bits, so 32*8 = 256 bits. Hence 1 bit for each character
	memset(exists,0,sizeof(exists));
	int block, bit, shift;
	int str_len = str.length();
	for(int i=0;i<str_len;i++)
	{
		block = str[i]/32; //which index/block in exists it should go to
		shift = str[i]%32; //used to shift 1 to a particular location
		bit = 1<<shift;
		if(exists[block] & bit)
		{
			return false;
		}
		exists[block] |= bit;
	}
	return true;
}

bool all_unique_chars_3(string str)
{
	map <int,char> my_hash;
	int str_len = str.length();
	for(int i=0;i<str_len;i++)
	{
		if(my_hash.find((int)str[i]) == my_hash.end()) //means the character was not found in the hash
		{
			my_hash.insert(make_pair((int)str[i], str[i])); //insert into the hash if its not already in
		}
		else
		{
			return false; //if the character was already in hash it has occured again in the given string
		}
	}
	return true;
}

int main()
{
	cout << all_unique_chars("quick!_brown?") << endl;
	cout << all_unique_chars("quick!_broun?") << endl;
	cout << all_unique_chars_2("quick!_brown?") << endl;
	cout << all_unique_chars_2("quick!_broun?") << endl;
	cout << all_unique_chars_3("quick!_brown?") << endl;
	cout << all_unique_chars_3("quick!_broun?") << endl;
	return 0;
}
