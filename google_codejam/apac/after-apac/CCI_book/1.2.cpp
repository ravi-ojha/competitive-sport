#include <bits/stdc++.h>
using namespace std;
void reverse(char * s)
{
	int s_len = strlen(s);
	for(int i=0;i<s_len/2;i++)
	{
		char temp = s[i];
		s[i] = s[s_len-1-i];
		s[s_len-1-i] = temp;
	}
}
int main()
{
	char a[5] = "rowk";
	reverse(a);
	printf("%s\n",a);
	char b[6] = "qwert";
	reverse(b);
	printf("%s\n",b);
	return 0;
}
