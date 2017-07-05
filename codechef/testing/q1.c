#include<stdio.h>
int main()
{
    int a[10],b[10],i,t;
    for(i=0;i<10;i++)
    {
        t = rand()%9;
        while(t==0)
        {
            t = rand()%9;
        }
        a[i] = t;
        b[i] = (i+1)*a[i];
    }
    for(i=0;i<10;i++)
    {
        printf(" %4d",a[i]);
    }
    printf(" \n");
    for(i=0;i<10;i++)
    {
        printf(" %4d",b[i]);
    }
    return 0;
}
