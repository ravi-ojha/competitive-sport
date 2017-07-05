#include<iostream>
#include<cstdio>
#define MOD 1000000009
using namespace std;
inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
     neg = 1;
     c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
     x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
     x = -x;
}
long long fast_pow(int a,int n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
        {
            result = result*value;
            result = result%MOD;
        }
        value = value*value;
        value = value%MOD;
        power = power >> 1;
    }
    return result;
}
int main()
{
    int i,j,k;
    int mult_inv[100011] = {0};
    for(i=0;i<100011;i++)
    {
        mult_inv[i] = fast_pow(i,MOD-2);
    }
    int t;
    //scanf(" %d",&t);
    fastRead_int(t);
    while(t--)
    {
        int n,q;
        //scanf(" %d %d",&n,&q);
        fastRead_int(n);
        fastRead_int(q);
        int a[n];
        for(i=0;i<n;i++)
        {
            fastRead_int(a[i]);
            //scanf(" %d",&a[i]);
        }
        while(q--)
        {
            int m;
            //scanf(" %d",&m);
            fastRead_int(m);
            long long dp[2][111] ={{0},{0}};
            dp[0][0] = 1;
            long long help[111] = {0};
            for(i=0;i<n;i++)
            {
                int tmp = a[i]%m + m;
                tmp %= m;
                help[tmp]++;
            }
            int flag = 0;
            for(i=0;i<m;i++)
            {
                if(!help[i])
                {
                    continue;
                }
                flag = 1 - flag;
                long long goku[111] = {0};
                long long z;
                z = 1;
                for(j=0;j<=help[i];j++)
                {
                    int tmp = i*j;
                    tmp %= m;
                    goku[tmp] += z;
                    goku[tmp] %= MOD;
                    z = z * (help[i]-j);
                    z %= MOD;
                    z = z * mult_inv[j+1];
                    z %= MOD;
                }
                for(j=0;j<m;j++)
                {
                    for(k=0;k<m;k++)
                    {
                        int tmp = j-k+m;
                        tmp %= m;
                        dp[flag][j] += dp[1-flag][tmp]*goku[k];
                        dp[flag][j] %= MOD;
                    }
                }
                for(j=0;j<111;j++)
                {
                    dp[1-flag][j] = 0;
                }
            }
            printf("%lld\n",dp[flag][0]);
        }
    }
    return 0;
}
