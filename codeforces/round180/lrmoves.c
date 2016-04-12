#include<stdio.h>
int main()
{
    int p,s,t,flagR = 0;
    char a[1005];
    scanf(" %d",&p);
    scanf(" %s",a);
    int i = 0;
    while(i<p)
    {
        if(a[i] == '.')
        {
            i++;
        }
        if(a[i] == 'R')
        {
            s = i;
            flagR = 1;
            break;
        }
        if(a[i] == 'L')
        {
            t = i-1;
            flagR = 0;
            break;
        }
    }
    if(flagR == 1)
    {
        while(a[i] == 'R')
        {
            i++;
        }
        if(a[i] == '.')
        t = i;
        else
        t = i-1;
        printf("%d %d\n",s+1,t+1);
    }
    else
    {
        while(a[i] == 'L')
        {
            i++;
        }
        s = i;
        printf("%d %d",s,t+1);
    }
    return 0;
}
