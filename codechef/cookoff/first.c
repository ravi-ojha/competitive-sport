#include<stdio.h>
int main()
{
    int T;
    int d1,d2,d;
    float ans;
    scanf(" %d",&T);
    while(T--)
    {
        scanf(" %d %d %d",&d1,&d2,&d);
        if (d>=d1+d2)
        {
            ans = d-d1-d2;
        }
        else if(d2>d+d1)
        {
            ans = d2-d-d1;
        }
        else if(d1>d+d2)
        {
            ans = d1-d-d2;

        }
        printf("%f",ans);
//        ans = d - (d1+d2);
//        if (ans < 0)
//            printf("0\n");
//        else
//            printf("%.16Lf\n",ans);
    }
    return 0;
}
