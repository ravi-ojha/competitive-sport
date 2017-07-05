#include<stdio.h>
int main()
{
    long long sum = 0;
    char c;
    int i;
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    for(i=0;i<100*50;i++)
    {
        scanf(" %c",&c);
        //printf("%c\t",c);
        sum = sum + a[c-48];
    }
    printf("sum = %lld",sum);
    return 0;
}
