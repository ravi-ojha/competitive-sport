#include<stdio.h>

long long combi(int n,int k)
{
    long long ans=1;
    //k=k>n-k?n-k:k;
    int j;
    for(j=1;j<=k;j++,n--)
    {
        if (n%j==0)
        {
            ans*=n/j;
            //ans = ans%1000000007;
        }
        else if (ans%j==0)
        {
            ans=ans/j*n;
            //ans = ans%1000000007;
        }
        else
        {
            ans=(ans*n)/j;
            //ans = ans%1000000007;
        }
    }
    return ans%1000000007;
}

int main()
{
    int n,r;
    scanf(" %d %d",&n,&r);
    printf(" %llu",combi(n,r));
}
