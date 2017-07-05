#include<stdio.h>
int main()
{
    int t;
    //scanf(" %d",&t);
    t = 2500;
    while(t <= 2500)
    {
        int n;
        //scanf(" %d",&n);
        n = t;
        int x,y;
        long long res = 0;
        x = 1;
        while(x<n)
        {
            y = n-x;
            int limit = x*y - 1;
            int k = 1;
            while(k <= limit)
            {
                if(limit/k == 1)
                {
                    res = res + limit - k + 1;
                    break;
                }
                res = res + limit/k;
                k++;
            }
            x++;
        }
        printf("%lld,",res);
        t++;
    }
    return 0;
}
