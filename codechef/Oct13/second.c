#include<stdio.h>
int main()
{
    int i=0,j=0,k=0;
    int n;
    scanf("%d",&n);
if(n==1)
{   for(k=0;k<2;k++)
{

    for(i=0;i<2;i++)
    {
        printf("1");
    }
    printf("\n");
}}

else
{

    for(i=0;i<n;i++)
    {

    for(j=1;j<n-i+1;j++)
       {
           printf("%d",j);
       }

       for(j=0;j<i*2;j++)
       {

           printf("0");
       }

       for(j=n-i;j>=1;j--)
       {
           printf("%d",j);
       }
       printf("\n");
    }

     for(i=n-1;i>0;i--)
    {

    for(j=1;j<=n-i+1;j++)
       {
           printf("%d",j);
       }

       for(j=2;j<i*2;j++)
       {

           printf("0");
       }

       for(j=n-i+1;j>=1;j--)
       {
           printf("%d",j);
       }
       printf("\n");
    }
}
/*
for(i=0;i<n-1;i++)
{
    for(j=1;j<i+2;j++)
    {

        printf("%d",j);
    }

    for(j=i*2+2;j>=1;j--)
    {
        printf("0");

    }
    for(k=n-i-1;k>=1;k--)
    {
        printf("%d",k);
    }
    printf("\n");
}
*/
    return 0;
}
