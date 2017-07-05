#include<stdio.h>
int main()
{
    int withdraw;
    float balance;
    scanf(" %d %f",&withdraw,&balance);
    if(withdraw>balance-0.50 || withdraw%5 != 0)
    {
        printf("%.2f",balance);
        return 0;
    }
    else
    {
        printf("%.2f",balance-0.50-withdraw);
        return 0;
    }
}
