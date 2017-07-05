#include<stdio.h>
int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9},i,u,v,w,x,y,z,max = 0;
    char mystr[1002];
    scanf(" %s",mystr);
    for(i=0;i<996;i++)
    {
        z = a[mystr[i]-48]*a[mystr[i+1]-48]*a[mystr[i+2]-48]*a[mystr[i+3]-48]*a[mystr[i+4]-48];
        printf(" %d",z);
        if (z > max)
        {
            max = z;
        }
    }
    printf("\n %d",max);
    return 0;
}
