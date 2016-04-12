#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[200001];
	char t[200001];
	scanf(" %s %s",s,t);
	int slen = strlen(s);
	int tlen = strlen(t);
	int freq[256] = {0};
	for(int i=0;i<slen;i++)
	{
		freq[s[i]]++;
	}
	int greq[256] = {0};
	for(int i=0;i<tlen;i++)
	{
		greq[t[i]]++;
	}
	int yay = 0;
	for(int i=0;i<256;i++)
	{
		if(freq[i])
		{
			if(freq[i] <= greq[i])
			{
				yay += freq[i];
				greq[i] = greq[i] - freq[i];
				freq[i] = 0;
			}
			else
			{
				yay += greq[i];
				freq[i] = freq[i] - greq[i];
				greq[i] = 0;
			}
		}
	}
	int whoops = 0;
	for(int i=0;i<256;i++)
	{
		if(freq[i])
		{
			if(i<96)
			{
				if(freq[i] <= greq[i+32])
				{
					whoops += freq[i];
					greq[i+32] = greq[i+32] - freq[i];
					freq[i] = 0;
				}
				else
				{
					whoops += greq[i+32];
					freq[i] = freq[i] - greq[i+32];
					greq[i+32] = 0;
				}
			}
			else
			{
				if(freq[i] <= greq[i-32])
				{
					whoops += freq[i];
					greq[i-32] = greq[i-32] - freq[i];
					freq[i] = 0;
				}
				else
				{
					whoops += greq[i-32];
					freq[i] = freq[i] - greq[i-32];
					greq[i-32] = 0;
				}
			}
		}
	}
	cout << yay << " " << whoops << endl;
	return 0;
}
