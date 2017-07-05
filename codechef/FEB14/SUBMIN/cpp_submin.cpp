#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int get_count(int a[], int k, int n, int p)
{
    int left = 0;
    int right = 0;
    int pp = p;
    while(pp>=0 && a[pp] >= k)
    {
        left++;
        pp--;
    }
    pp = p;
    while(pp<n && a[pp] >= k)
    {
        right++;
        pp++;
    }
    return left*right;
}
int main()
{
    int n,q,i;
    scanf(" %d",&n);
    int a[55];
    for(i=0;i<n;i++)
    {
        scanf(" %d",&a[i]);
    }
    scanf(" %d",&q);
    while(q--)
    {
        int res = 0,k;
        scanf(" %d",&k);
        for(i=0;i<n;i++)
        {
            if(a[i] == k)
            {
                res += get_count(a,k,n,i);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
