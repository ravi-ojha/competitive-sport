#include<stdio.h>
int main()
{
    int i;
    printf("100000\n");
    for(i=0;i<100000;i++)
    {
        printf("%d ",rand()%100000000);
    }
    printf("\n");
    printf("100000\n");
    for(i=0;i<100000;i++)
    {
        printf("%d %d \n",rand()%100000,rand()%100000);
    }
    printf("\n");
}
