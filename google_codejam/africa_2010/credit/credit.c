#include<stdio.h>
int main()
{
    int T,p;
    scanf(" %d",&T);
    for(p=1;p<=T;p++)
    {
        int c,I,i,j;
        int a[2001];
        scanf(" %d %d",&c,&I);
        for(i=1;i<=I;i++)
        {
            scanf(" %d",&a[i]);
        }
        for(i=1;i<=I;i++)
        {
            for(j=i+1;j<=I;j++)
            {
                if(a[i] + a[j] == c)
                goto hell;
            }
        }
        hell:
        printf("Case #%d: %d %d\n",p,i,j);
    }
    return 0;
}
