#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		char s[11];
		scanf(" %s",s);
		int slen = strlen(s);
		int ans;
		sscanf(s, " %d", &ans);
		int ans0;
		sscanf(s, " %d", &ans0);
		for(int j=0;j<slen;j++)
		{
			int mx_idx = j;
			int mx_idx0 = j;
			for(int i=j+1;i<slen;i++)
			{
				if(s[mx_idx] <= s[i])
				{
					mx_idx = i;
				}
				if(s[mx_idx0] >= s[i])
				{
					mx_idx0 = i;
				}
			}
			char tmp = s[j];
			s[j] = s[mx_idx];
			s[mx_idx] = tmp;
			int res;
			sscanf(s, " %d", &res);
			ans = max(res, ans);
			tmp = s[j];
			s[j] = s[mx_idx];
			s[mx_idx] = tmp;
			if(j==0 && s[j] != '0' && s[mx_idx0] == '0')
			{
				continue;
			}
			tmp = s[j];
			s[j] = s[mx_idx0];
			s[mx_idx0] = tmp;
			int res0;
			sscanf(s, " %d", &res0);
			ans0 = min(res0, ans0);
			tmp = s[j];
			s[j] = s[mx_idx0];
			s[mx_idx0] = tmp;
		}
		printf("Case #%d: %d %d\n",tt,ans0,ans);
	}
	return 0;
}

