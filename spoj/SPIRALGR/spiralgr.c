#include<stdio.h>
#define LIMIT 26
int main()
{
    int a[LIMIT][LIMIT];
    int v = LIMIT*LIMIT,i=0,j=0,p=0,m,n;
    while(v != 0)
    {
        //printf("check");
        while(j<(LIMIT-p))
        {
            a[i][j] = v;
            v--;
            j++;
        }
        i++;
        j--;
        while(i<(LIMIT-p))
        {
            a[i][j] = v;
            v--;
            i++;
        }
        j--;
        i--;
        while(j>=p)
        {
            a[i][j] = v;
            v--;
            j--;
        }
        i--;
        j++;
        while(i>=(p+1))
        {
            a[i][j] = v;
            v--;
            i--;
        }
        //v++;
        p++;
        i = p;
        j = p;
        //break;
    }
    for(m=0;m<LIMIT;m++)
    {
        for(n=0;n<LIMIT;n++)
        {
            printf("%4d",a[m][n]);
        }
        printf("\n");
    }
}
