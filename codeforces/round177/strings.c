#include<stdio.h>
int main()
{
    int i,t,n,k,p;
    char a[1000000];
    for(i=0;i<1000000;i=i+2)
    {
        a[i] = 'a';
        a[i+1] = 'b';
    }
    scanf(" %d %d",&n,&k);
    if(k>n)
    {
        printf("-1\n");
        return 0;
    }
    if(n>1 && k==1)
    {
        printf("-1\n");
        return 0;
    }
    t = n - k;
    if(t%2 == 1)
    {
        p = 99;
        t = t+2;
        while(t<n)
        {
            a[t] = p;
            t++;
            p++;
        }
        a[t] = '\0';
    }
    else
    {
        p = 97;
        while(t<n)
        {
            a[t] = p;
            t++;
            p++;
        }
        a[t] = '\0';
    }
    printf("%s",a);
    return 0;
}
