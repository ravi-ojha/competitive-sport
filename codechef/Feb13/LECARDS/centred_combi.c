#include<stdio.h>

long long int centred_combi(int n, int r)
{
    int i = 2;
    int j = r+2;
    long long int ans = r+1;
    long long int temp;
    while(i<=r)
    {
        if(j%i == 0)
        {
            temp = j/i;
            ans = ans*temp;
            ans = ans%1000000007;
        }
        else if(ans%i == 0)
        {
            temp = ans/i;
            ans = temp*j;
            ans = ans%1000000007;
        }
        else
        {
            //printf("\tcheck");
            ans = (ans*j)/i;
            ans = ans%1000000007;
        }
        i++;
        j++;
    }
    return ans%1000000007;
}

//long long combi(int n,int k)
//{
//    long long ans=1;
//    k=k>n-k?n-k:k;
//    int j=1;
//    for(;j<=k;j++,n--)
//    {
//        if(n%j==0)
//        {
//            ans*=n/j;
//            ans = ans%1000000007;
//        }else
//        if(ans%j==0)
//        {
//            ans=ans/j*n;
//            ans = ans%1000000007;
//        }else
//        {
//            ans=(ans*n)/j;
//            ans = ans%1000000007;
//        }
//    }
//    return ans%1000000007;
//}

int main()
{
    int n,r;
    scanf(" %d",&n);
    r = n/2;
    printf("%llu\n",centred_combi(n,r));
    //printf("%llu\n",combi(n,r));
}


