#include<stdio.h>
int main()
{
    int t,i,j;
    scanf(" %d",&t);
    char a[t][t];
    for(i=0;i<t;i++)
    {
        for(j=0;j<t;j++)
        scanf(" %c",&a[i][j]);
    }
    for(i=0;i<t;i++)
    {
        for(j=0;j<t;j++)
        printf(" %c",a[i][j]);
        printf("\n");
    }
    for(i=0;i<t;i++)
    {
        for(j=0;j<t;j++)
        {
            if(a[i][j] == '1')
            {
                l2 = j;
                l3 = j+1;
                for(k=i+1;k<t;k++)
                {
                    if((j-1)>=0)
                    {
                        l1 = j-1;
                        if(a[k][l1] == '1')
                        {

                        }
                    }
                }
            }
        }
    }
}
