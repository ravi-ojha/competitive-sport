#include<stdio.h>
int main()
{
    int t,p;
    scanf(" %d",&t);
    char a[600];
    char b[600];
    char c[600];
    char d[600];
    for(i=0;i<600;i++)
    {
        if(i%4 == 0)
        {
            a[i] = 'E';
            b[i] = 'W';
            c[i] = 'N';
            d[i] = 'S';
        }
        else if(i%4 == 1)
        {
            a[i] = 'N';
            b[i] = 'N';
            c[i] = 'E';
            d[i] = 'E';
        }
        else if(i%4 == 2)
        {
            a[i] = 'W';
            b[i] = 'E';
            c[i] = 'S';
            d[i] = 'N';
        }
        else
        {
            a[i] = 'S';
            b[i] = 'S';
            c[i] = 'W';
            d[i] = 'W';
        }
    }
    for(p=1;p<=t;p++)
    {
        int x,y;
        scanf(" %d %d",&x,&y);
        int modx,mody;
        if(x<0)
        {
            modx = -x;
        }
        else
        {
            modx = x;
        }
        if(y<0)
        {
            mody = -y;
        };
        else
        {
            mody = y
        }
        if(x == y)
        {

        }
    }
}
