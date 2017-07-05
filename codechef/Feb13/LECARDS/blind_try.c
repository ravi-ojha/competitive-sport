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

long long iter_pow(int a,int n)
{
    long long ans = 1;
    long long power = a;
    while(n>0)
    {
        if(n%2 == 1)
            {ans = ans*power;
            ans = ans%1000000007;}
        power = power*power;
        power = power%1000000007;
        n /= 2;
    }
    return ans;
}
int main()
{
    int T;
    scanf(" %d",&T);
    while(T--)
    {
        long long m = 0;
        long long comb = 0;
        int n,i,r;
        scanf(" %d",&n);
        //printf("n = %d\n",n);
        for(i=0;i<n;i++)
        scanf(" %d",&r);
        //printf("\n\n %llu",combi(n,r));
        //m = 2<<(n-1);
        m = iter_pow(2,n);
        //printf("m = %d",m);
        if(n&1)
        {
            m = m/2;
            printf("%llu\n",m);
        }
        else
        {
            comb = centred_combi(n,n/2);
            //printf("\ncombi value %llu",comb);
            if(m>comb)
            m = m-comb;
            else
            m = comb-m;
            //printf("\nm after sub = %llu",m);
            m = m/2;
            //printf("\nm after div = %llu",m);
            printf("%llu\n",m);
        }
    }
    return 0;
}
