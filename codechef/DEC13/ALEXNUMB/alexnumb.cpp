#include<iostream>
#include<cstdio>
int main()
{
    int t,i;
    scanf(" %d",&t);
    while(t--)
    {
        long long n;
        scanf(" %lld",&n);
        long long a[n];
        for(i=0;i<n;i++)
        {
            scanf(" %lld",&a[i]);
        }
        printf("%lld\n",(n*(n-1))/2);
    }
    return 0;
}
