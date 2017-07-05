#include<stdio.h>
int main()
{
    int T,N,M,ans,RATIO;
    scanf(" %d",&T);
    while(T--)
    {
        M=5;
        ans = 0;
        scanf(" %d",&N);
        RATIO = N/M;
        while(RATIO != 0)
        {
            ans = ans + RATIO;
            M = M*5;
            RATIO = N/M;
        }
        printf("%d\n",ans);
    }
    return 0;
}
