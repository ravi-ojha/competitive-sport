#include<stdio.h>
int main()
{
    int t;
    //scanf(" %d",&t);
    FILE *f;
    f = fopen("hard.txt","w");
    t = 3;
    while(t <= 2500)
    {
        int n;
        //scanf(" %d",&n);
        n = t;
        printf("t = %d\n",t);
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
                res = res + limit/k;
                k++;
            }
            x++;
        }
        fprintf(f,"%lld,",res);
        t++;
    }
    return 0;
}
