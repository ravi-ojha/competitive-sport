#include<cstdio>
#include<iostream>
using namespace std;
#define MOD 1000000007
long long pow_2[200010];

void cal_pow_2()
{
    pow_2[0]=1;
    int i;
    for(i=1;i<200010;i++)
    {
        pow_2[i] = pow_2[i-1]*2;
        pow_2[i] %= MOD;
    }
}

int main()
{
    cal_pow_2();
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,i,j,shift;
        long long tmp;
        scanf(" %d",&n);
        tmp = n+1;
        int a[200010];
        for(i=0;i<n;i++)
        {
            scanf(" %d",&a[i]);
        }
        int goku[101][201] = {0}, gohan[101] = {0};
        gohan[a[0]]++;
        for(i=2;i<=n;i++)
        {
            for(j=1;j<=100;j++)
            {
                if(gohan[j] > 0)
                {
                    shift = a[i-1] - j;
                    tmp = tmp + goku[j][shift+99] + gohan[j];
                    tmp %= MOD;
                    goku[a[i-1]][shift+99] = goku[a[i-1]][shift+99] + goku[j][shift+99] + gohan[j];
                    goku[a[i-1]][shift+99] %= MOD;
                }
            }
            gohan[a[i-1]]++;
        }
        long long res = pow_2[n] - tmp;
        if(res >= 0)
        {
            printf("%lld\n",res);
        }
        else
        {
            printf("%lld\n",res+MOD);
        }
    }
    return 0;
}