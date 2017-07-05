#include <bits/stdc++.h>
using namespace std;
int fast_int()
{
    int n = 0;
    char c = getchar();
    while (!('0' <= c && c <= '9'))
    {
        c = getchar();
    }
    while ('0' <= c && c <= '9')
    {
        n = (n<<3)+(n<<1) + c - '0';
        c = getchar();
    }
    return n;
}
#define MAX 2009
bool check[MAX]={false};
int total=0;
int dfs(vector<int> v[],int root)
{
    int m,m1=-1,m2=-1;
    check[root]=1;
    for(int i=0;i<v[root].size();i++)
    {
        if(!check[v[root][i]]){
            m = dfs(v,v[root][i]);
            if(m>=m1)
            {
                m2= m1;
                m1 = m;
            }
            else if(m>m2)
                m2=m;
        }
    }
    total = max(total , m1+m2+2);
    return (m1 + 1);
}
int main()
{
    int t;
    //scanf(" %d",&t);
    t = fast_int();
    while(t--)
    {
        for(int i =0; i< MAX;i++)
        {
            check[i] = false;
        }
        int n,a,b;
        //scanf(" %d",&n);
        n = fast_int();
        vector<int> v[n+9];
        for(int i=0;i<(n-1);i++)
        {
            //scanf(" %d %d",&a,&b);
            a = fast_int();
            b = fast_int();
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(v,0);
        printf("%d\n",total+1);
        total = 0;
    }
    return 0;
}
