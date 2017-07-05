#include<cstdio>
#include<iostream>
using namespace std;
int is_prime[3000] = {0};
void sieve()
{
    is_prime[0] = 1;
    is_prime[1] = 1;
    int i = 2;
    while(i*i<=3000)
    {
        int j = i*2;
        if(!is_prime[i])
        {
            while(j<=3000)
            {
                is_prime[j] = 1;
                j += i;
            }
        }
        i++;
    }
}
int main()
{
    int t;
    scanf(" %d",&t);
    sieve();
    while(t--)
    {
        int x,y;
        scanf(" %d %d",&x,&y);
        int z = x+y;
        int res = 1;
        while(is_prime[z+res] != 0)
        {
            res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
