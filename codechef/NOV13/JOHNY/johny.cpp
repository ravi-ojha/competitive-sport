#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,i;
        scanf(" %d",&n);
        int a[n];
        for(i=0;i<n;i++)
        {
            scanf(" %d",&a[i]);
        }
        int k,c=0;
        scanf(" %d",&k);
        int z = a[k-1];
        for(i=0;i<n;i++)
        {
            if(a[i]<z)
            {
                c += 1;
            }
        }
        printf("%d\n",c+1);
    }
    return 0;
}
