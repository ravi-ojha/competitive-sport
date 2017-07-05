#include<stdio.h>
int fctrs(long long k)
{
    //long long k = 600851475143;
    long long l,i;
    //k = 21;
    l = k;
    long long a[100000],j=0;
    i = 2;
    while(i*i<=k)
    {
        if(l%i == 0)
        {
            //l = l/i;
            a[j] = i;
            j++;
            if(l/i != i)
            {a[j] = l/i;
            j++;}
            i++;
        }
        else
        i++;
    }
//    for(i=0;i<j;i++)
//    {
//        printf("  %lld",a[i]);
//    }
    return j+1;
}
int main()
{
    long long i,n,j;
    for(i=1;1;i++)
    {
        n = i*(i+1)/2;
        j = fctrs(n);
        if(j>500)
        {
            printf(" %lld",n);
            return 0;
        }
    }
    //return 0;
}
