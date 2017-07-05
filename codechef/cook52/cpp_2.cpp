#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int a[5][5] = {{1,1,0,0,1},{1,1,1,0,0},{0,1,1,1,0},{0,0,1,1,1},{1,0,0,1,1}};
int b[5][5] = {{1,0,1,1,0},{0,1,0,1,1},{1,0,1,0,1},{1,1,0,1,0},{0,1,1,0,1}};
int main()
{
	int t;
/*	for(int i = 0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf(" %2d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	for(int i = 0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf(" %2d",b[i][j]);
		}
		printf("\n");
	}*/
	scanf(" %d",&t);
	while(t--)
	{
		char s[100001];
		scanf(" %s",s);
		string res = "";
		int slen = strlen(s);
		int outer = 1;
		for(int i=0;i<(slen-1);i++)
		{
			if(outer)
			{
				if(a[s[i]-'A'][s[i+1]-'A'])
				{
					res.push_back(s[i]-'A'+'0');
					if(s[i] == s[i+1]) //toggle outer
					{
						outer = 0; //since outer is 1
					}
				}
			}
			else
			{
				if(b[s[i]-'A'][s[i+1]-'A'])
				{
					res.push_back(s[i]-'A'+5+'0');
					if(s[i] == s[i+1])
					{
						outer = 1;
					}
				}
			}
		}
		if(outer)
		{
			res.push_back(s[slen-1]-'A'+'0');
		}
		else
		{
			res.push_back(s[slen-1]-'A'+5+'0');
		}
		outer = 0;
		int flag = 1;
		if(res.length() != slen)
		{
			res = "";
			flag = 0;
		}
		if(flag == 0)
		{
			flag = 1;
			for(int i=0;i<(slen-1);i++)
			{
				if(outer)
				{
					if(a[s[i]-'A'][s[i+1]-'A'])
					{
						res.push_back(s[i]-'A'+'0');
						if(s[i] == s[i+1]) //toggle outer
						{
							outer = 0; //since outer is 1
						}
					}
				}
				else
				{
					if(b[s[i]-'A'][s[i+1]-'A'])
					{
						res.push_back(s[i]-'A'+5+'0');
						if(s[i] == s[i+1])
						{
							outer = 1;
						}
					}
				}
			}
			if(outer)
			{
				res.push_back(s[slen-1]-'A'+'0');
			}
			else
			{
				res.push_back(s[slen-1]-'A'+5+'0');
			}
			if(res.length() != slen)
			{
				res = "-1";
			}
		}
		cout << res << endl;
		//printf("%s\n",res);
	}
	return 0;
}
