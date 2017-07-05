#include<iostream>
#include<cstdio>
using namespace std;
int parent[100001];
int connected[100001];
int tax[100001];
int abs_tax[100001];
int find_parent(int child)
{
    if(parent[child] == child)
    {
        return child;
    }
    else
    {
        parent[child] = find_parent(parent[child]);
        return parent[child];
    }
}
void unite(int x, int y)
{
    parent[find_parent(y)] = find_parent(x);
}
int main()
{
    int n, m, i, x, y;
    scanf(" %d %d",&n,&m);
    for(i=0;i<=n;i++)
    {
        parent[i] = i;
        connected[i] = 0;
    }
    for(i=0;i<m;i++)
    {
        scanf(" %d %d",&x,&y);
        unite(x,y);
    }
    for(i=1;i<=n;i++)
    {
        scanf(" %d",&tax[i]);
        abs_tax[i] = 100000;

    }
    for(i=1;i<=n;i++)
    {
        int z = find_parent(i);
        connected[z]++;
        if(tax[i]>=0)
        {
            abs_tax[z] = min(tax[i],abs_tax[z]);
        }
    }
    int components = 0;
    int sum = 0;
    int least = 100000;
    int flag = 0;
    for(i=1;i<=n;i++)
    {
        if(connected[i])
        {
            components++;
            //printf(" here %d\n",abs_tax[i]);
            sum += abs_tax[i];
            if(abs_tax[i] > 10000)
            {
                flag = 1;
                break;
            }
            least = min(least,abs_tax[i]);
        }
    }
    if(components == 1)
    {
        printf("0\n");
    }
    else if(flag)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",(components-1)*least + sum - least);
    }
    return 0;
}
