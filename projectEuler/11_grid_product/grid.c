#include<stdio.h>
int main()
{
    int a[20][20],i,j,ans,max=0;
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            scanf(" %d",&a[i][j]);
        }
    }
//    for(i=0;i<20;i++)
//    {
//        for(j=0;j<20;j++)
//        {
//            printf("%4d",a[i][j]);
//        }
//        printf("\n");
//    }
    for(i=0;i<17;i++)
    {
        for(j=0;j<17;j++)
        {
            ans = a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3];
            if(ans>max)
            {
                max = ans;
            }
            ans = a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
            if(ans>max)
            {
                max = ans;
            }
            ans = a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j];
            if(ans>max)
            {
                max = ans;
            }
            if(j>2)
            {
                ans = a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3];
                if(ans>max)
                {
                    max = ans;
                }
            }
        }
    }
    printf("max = %d",max);
}
