#include<stdio.h>
int main()
{
    long long i,j,l=1,max=0,maxlen = 0;
    for(i=13;i<1000000;i++)
    {
        j = i;
        l = 1;
        while(j!=1)
        {
            if(j&1)
            {
                j = 3*j + 1;
            }
            else
            {
                j = j/2;
            }
            l++;
        }
        if(l>maxlen)
        {
            max = i;
            maxlen = l;
        }
    }
    printf("max = %lld",max);
    return 0;
}
