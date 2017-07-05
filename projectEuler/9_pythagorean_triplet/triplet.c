#include<stdio.h>
int main()
{
    int i,j,k;
    for(i=1;i<999;i++)
    {
        for(j=i+1;j<(1000-i);j++)
        {
            k = 1000-i-j;
//            if(k<i || k<j || j<i)
//            {
//                continue;
//            }
            if( (k*k) == (i*i + j*j) )
            {
                printf(" i = %d  j = %d  k = %d\n",i,j,k);
                printf("i*j*k = %d",i*j*k);
                return 0;
            }
        }
    }
}
