#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t = 100;
	while(t--)
	{int  n,m,pocet=0;
	cin >>n>>m;
	int c=0,d=0;
	while(n<m)
	{
		c++;
		if(m%2 == 1)
			m++;
		else
			m/=2;
		pocet++;
	}
	c+=n-m;
	cout << c << endl;
}
	return 0;
}
