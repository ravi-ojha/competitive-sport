#include<stdio.h>
int main()
{
    long long int k = 600851475143,l,i;
    k = 21;
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
    for(i=0;i<j;i++)
    {
        printf("  %lld",a[i]);
    }
    return 0;
}
