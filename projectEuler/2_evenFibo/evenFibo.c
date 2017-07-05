#include<stdio.h>
int main()
{
    int i=1,j=2,k=0,sum=0;
    while(k<=4000000)
    {
        k = i+j;
        if(k%2 == 0)
        sum = sum+k;
        i = j;
        j = k;
    }
    printf(" %d",sum+2);
    return 0;
}
