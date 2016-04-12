#include <bits/stdc++.h>
using namespace std;

struct node
{
	int days;
	int idx;
};
bool compare(node const& lh, node const& rh)
{
	return lh.days < rh.days;
}
int main()
{
	int n,k;
	scanf(" %d %d",&n,&k);
	vector < node > v;
	for(int i=1;i<=n;i++)
	{
		node tmp;
		scanf(" %d",&tmp.days);
		tmp.idx = i;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end(), &compare);
	int i=0;
	int res = 0;
	vector < int > ans;
	while(i<n && res<k)
	{
		res += v[i].days;
		ans.push_back(v[i].idx);
		i++;
	}
	if(res>k)
	{
		i--;
		ans.pop_back();
	}
	printf("%d\n",i);
	for(int j=0;j<ans.size();j++)
	{
		printf("%d ",ans[j]);
	}
	return 0;
}
