#include<stdio.h>
int iter_pow(int n)
{
    int i,j;
    int ans[2][2] = {1,0,0,1};
    int b[2][2];
    int power[2][2] = {1,1,1,0};
    while(n)
    {
        if(n%2 == 1)
        {
            matrix_mul(ans,power,b);
            ans[0][0] = b[0][0];
            ans[0][1] = b[0][1];
            ans[1][0] = b[1][0];
            ans[1][1] = b[1][1];
        }
        matrix_mul(power,power,b);
        power[0][0] = b[0][0];
        power[0][1] = b[0][1];
        power[1][0] = b[1][0];
        power[1][1] = b[1][1];
        n /= 2;
    }
    printf("\n\nNow\n\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%5d",ans[i][j]);
        }
        printf("\n");
    }
    //return ans;
}

int matrix_mul(int a[][2], int b[][2],int c[][2])
{
    int i,j;
    c[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    c[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    c[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    c[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
    printf("\n\n another\n\n");
    for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
            {
                printf("%5d",c[i][j]);
            }
            printf("\n");
        }
}
int main()
{
    int n,i,j;
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        scanf(" %d",&n);
    iter_pow(n);

    }
//    printf("\n\nPower = %d\n\n",n);
//    for(i=0;i<2;i++)
//        {
//            for(j=0;j<2;j++)
//            {
//                printf("%5d",a[i][j]);
//            }
//            printf("\n");
//        }
}
