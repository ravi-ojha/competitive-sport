#include<stdio.h>
#define MAX 1000

// assuming n can be at most 100
long long int triangle[MAX + 1][MAX + 1];

void makeTriangle()
{
    int i, j;
    // initialize the first row
    triangle[0][0] = 1; // C(0, 0) = 1
    //triangle[0][1] = 1;
    for(i = 1; i <= MAX; i++)
    {
        triangle[i][0] = 1; // C(i, 0) = 1
        for(j = 1; j <= i; j++)
        {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            triangle[i][j] = triangle[i][j]%1000000007;
            //printf("\t %d",triangle[i][j]);
        }
        //triangle[i][j] = 1;
        //printf("\t %d\n",triangle[i][j]);
    }
}

int main()
{
    int i,j;
    long long int sum;
    makeTriangle();
    for(i=1;i<=MAX;i++)
    {
        sum = 0;
        for(j=i/2+1;j<=i;j++)
        {
            //if(i%2 == 1 && j==2)
            //printf("\t %d",triangle[i][j]);
            sum = sum + triangle[i][j];
            sum = sum%1000000007;
        }
        printf("%llu,",sum);
        //printf("\nsum = %d",sum);
    }
}
