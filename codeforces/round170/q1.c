#include<stdio.h>
int main()
{
    int i;
    int T;
    scanf(" %d",&T);
    int c[T],sum=0;
    for(i=0;i<T;i++)
    {
        scanf(" %d",&c[i]);
        sum = sum+c[i];
    }
    //printf("sum = %d\n",sum);
    int s, t, d1=0, d2;
    scanf(" %d",&s);
    scanf(" %d",&t);
    if(s>t)
    {
        int temp = s;
        s = t;
        t = temp;
    }
    for(i=s-1;i<t-1;i++)
    {
        d1 = d1+c[i];
    }
    //printf("calc d1 = %d\n",d1);
    d2 = sum-d1;
    if(d1>d2)
    printf("%d\n",d2);
    else
    printf("%d\n",d1);
    return 0;
}
