#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		string s;
		cin >> s;
		int slen = s.length();
		int res = INT_MAX;
		// try to make rgb
		int r=0,g=0,b=0;
		int rd = 0, gd = 0, bd = 0;
		for(int i=0;i<slen;i++)
		{
			if(s[i] == 'r')
			{
				rd = rd+(i-r);
				r++;
			}
			/*if(s[i] == 'g')
			{
				gd = gd+(i-g);
				g++;
			}
			if(s[i] == 'b')
			{
				bd = bd+(i-b);
				b++;
			}*/
		}
		r=slen-1,g=slen-1,b=slen-1;
		int rc = 0, gc = 0, bc = 0;

		for(int i=slen-1;i>=0;i--)
		{
			/*if(s[i] == 'r')
			{
				rc = rc+(r-i);
				r--;
			}*/
			if(s[i] == 'b')
			{
				bc = bc+(b-i);
				b--;
			}
			if(s[i] == 'r')
			{
				b--;
			}
			/*if(s[i] == 'g')
			{
				gc = gc+(g-i);
				g--;
			}*/
		}

		res = min(res,rd+bc); //rgb


		for(int i=slen-1;i>=0;i--)
		{
			/*if(s[i] == 'r')
			{
				rc = rc+(r-i);
				r--;
			}*/
			if(s[i] == 'g')
			{
				gc = gc+(g-i);
				g--;
			}
			if(s[i] == 'r')
			{
				g--;
			}
			/*if(s[i] == 'g')
			{
				gc = gc+(g-i);
				g--;
			}*/
		}

		res = min(res,rd+gc); //rbg


		r=0,g=0,b=0;
		rd = 0, gd = 0, bd = 0;
		for(int i=0;i<slen;i++)
		{
			if(s[i] == 'g')
			{
				gd = gd+(i-g);
				g++;
			}
			/*if(s[i] == 'g')
			{
				gd = gd+(i-g);
				g++;
			}
			if(s[i] == 'b')
			{
				bd = bd+(i-b);
				b++;
			}*/
		}
		r=slen-1,g=slen-1,b=slen-1;
		rc = 0, gc = 0, bc = 0;

		for(int i=slen-1;i>=0;i--)
		{
			/*if(s[i] == 'r')
			{
				rc = rc+(r-i);
				r--;
			}*/
			if(s[i] == 'b')
			{
				bc = bc+(b-i);
				b--;
			}
			if(s[i] == 'g')
			{
				b--;
			}
			/*if(s[i] == 'g')
			{
				gc = gc+(g-i);
				g--;
			}*/
		}

		res = min(res,gd+bc); //grb


		for(int i=slen-1;i>=0;i--)
		{
			if(s[i] == 'r')
			{
				rc = rc+(r-i);
				r--;
			}
			if(s[i] == 'g')
			{
				r--;
			}
			/*if(s[i] == 'g')
			{
				gc = gc+(g-i);
				g--;
			}*/
		}

		res = min(res,gd+rc); //gbr



		r=0,g=0,b=0;
		rd = 0, gd = 0, bd = 0;
		for(int i=0;i<slen;i++)
		{
			/*if(s[i] == 'r')
			{
				rd = rd+(i-r);
				r++;
			}*/
			/*if(s[i] == 'g')
			{
				gd = gd+(i-g);
				g++;
			}*/
			if(s[i] == 'b')
			{
				bd = bd+(i-b);
				b++;
			}
		}
		r=slen-1,g=slen-1,b=slen-1;
		rc = 0, gc = 0, bc = 0;

		for(int i=slen-1;i>=0;i--)
		{
			/*if(s[i] == 'r')
			{
				rc = rc+(r-i);
				r--;
			}*/
			if(s[i] == 'g')
			{
				gc = gc+(g-i);
				g--;
			}
			if(s[i] == 'b')
			{
				g--;
			}
			/*if(s[i] == 'g')
			{
				gc = gc+(g-i);
				g--;
			}*/
		}

		res = min(res,bd+gc); //brg


		for(int i=slen-1;i>=0;i--)
		{
			/*if(s[i] == 'r')
			{
				rc = rc+(r-i);
				r--;
			}*/
			if(s[i] == 'r')
			{
				rc = rc+(r-i);
				r--;
			}
			if(s[i] == 'b')
			{
				r--;
			}
			/*if(s[i] == 'g')
			{
				gc = gc+(g-i);
				g--;
			}*/
		}



		res = min(res,bd+rc); //bgr
		printf("%d\n",res);
	}
	return 0;
}
