#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1030][1030];
int main()
{
    //cout << "Hello World!" << endl;
    int n;
    scanf(" %d",&n);
    int len = pow(2,n) - 1;
    for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=i;j++)
		{
			scanf(" %d",&a[i+1][j]);
		}
	}
	queue <int> q1;
	for(int i=1;i<=(len+1);i++)
	{
		q1.push(i);
	}
	while(q1.size() != 1)
	{
		int p1 = q1.front();
		q1.pop();
		int p2 = q1.front();
		q1.pop();
		if(a[p2][p1])
		{
			q1.push(p2);
		}
		else
		{
			q1.push(p1);
		}
	}
	printf("%d\n",q1.front());
    return 0;
}
