#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
double round(double d)
{
  return (double)(int)d;
}
int main()
{
	int n;
	scanf(" %d",&n);
	vector < pair<int,int> > a;
	int i,j;
	for(i=0;i<n;i++)
	{
		int x,y;
		scanf(" %d %d",&x,&y);
		a.push_back(make_pair(x,y));
	}
	set < pair<int,int> > b;
	for(i=0;i<n;i++)
	{
		b.insert(a[i]);
	}
	int res = 2;
	if(n==0)
	{
		res = 4;
	}
	else if(n==1)
	{
		res = 3;
	}
	else if(n==2)
	{
		res = 2;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				double midX,midY,diffX,diffY;
				int pX,pY,qX,qY = 10000011;
				int tmp = 0;
				midX = (double)(a[i].first + a[j].first)/2;
				midY = (double)(a[i].second + a[j].second)/2;
				diffX = (double)(a[i].first - a[j].first)/2;
				diffY = (double)(a[i].second - a[j].second)/2;

				if(round(midX-diffY) == (midX-diffY))
				{
					pX = (int)(midX-diffY);
				}
				if(round(midY+diffX) == (midY+diffX))
				{
					pY = (int)(midY+diffX);
				}
				if(round(midX+diffY) == (midX+diffY))
				{
					qX = (int)(midX+diffY);
				}
				if(round(midY-diffX) == (midY-diffX))
				{
					qY = (int)(midY-diffX);
				}

				pair <int,int> p,q;
				p = make_pair(pX,pY);
				q = make_pair(qX,qY);

				if(b.find(p) != b.end())
				{
					tmp++;
				}
				if(b.find(q) != b.end())
				{
					tmp++;
				}

				if(res > (2-tmp))
				{
					res = 2-tmp;
				}
			}
		}
	}
	printf("%d\n",res);
	return 0;
}
