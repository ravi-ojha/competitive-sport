#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int pow2[12] = {1,2,4,8,16,32,64,128,256,512,1024};

long long dp[1024][101];
long long helper[1024][11][101];

int main()
{
    int t;
    scanf(" %d", &t);
    while(t--)
    {
        int n,i,j,k;
        scanf(" %d", &n);

        long long ppl[11] = {0};
        long long data[11][101];

        for(i=0; i<pow2[n]; i++)
        {
            for(j=0; j<101; j++)
            {
                dp[i][j] = 0;
            }
        }

        for(i=0; i<pow2[n]; i++)
        {
            for(j=0; j<n; j++)
            {
                for(k=0; k<101; k++)
                {
                    helper[i][j][k] = 0;
                }
            }
        }

        for(i=0; i<n; i++)
        {
            char ch = ' ';
            int id;
            while(ch != '\n')
            {
                scanf(" %d%c", &id, &ch);
                data[i][ppl[i]] = id;
                ppl[i]++;
            }
            sort(data[i], data[i] + ppl[i]);
        }

        dp[0][0] = 1;

        for(i=0; i<pow2[n]; i++)
        {
            for(j=0; j<101; j++)
            {
                for(k=0; k<n; k++)
                {
                    if(i & pow2[k])
                    {
                        int temp = upper_bound(data[k], data[k] + ppl[k], j) - data[k] - 1;
                        if(temp >= 0 && data[k][temp] == j)
                        {
                            long long res = 0;
                            for(int q=j; q>=0; q=((q + 1) & q)-1)
                            {
                                res += helper[i][k][q];
                                res %= 1000000007;
                            }
                            dp[i][j] += res;
                            dp[i][j] %= 1000000007;
                        }
                    }
                }
                if(dp[i][j] == 0)
                {
                    continue;
                }
                for(k=0; k<n; k++)
                {
                    if(i & pow2[k])
                    {
                        continue;
                    }
                    int temp = upper_bound(data[k], data[k] + ppl[k], j) - data[k];
                    if(temp < ppl[k])
                    {
                        int x,y,z;
                        x = i | pow2[k];
                        y = data[k][temp];
                        z = dp[i][j];
                        for(int q=y; q<101; q=((q + 1) | q))
                        {
                            helper[x][k][q] += z;
                        }
                    }
                }
            }
        }

        long long final = 0;
        for(i=0; i<101; i++)
        {
            final += dp[pow2[n]-1][i];
            final %= 1000000007;
        }
        printf("%lld\n", final);
    }
    return 0;
}