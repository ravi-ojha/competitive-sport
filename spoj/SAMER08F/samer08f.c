#include<stdio.h>
int main()
{
    int t;
    scanf(" %d",&t);
    while(t)
    {
        printf("%d\n",(t*(t+1)*(2*t+1))/6);
        scanf(" %d",&t);
    }
    return 0;
}
