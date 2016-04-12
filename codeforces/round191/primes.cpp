#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    char primes[1500001]={0};
    int n;
    scanf(" %d",&n);
    int i=0,countprimes=0;
    primes[0]=1;
    primes[1]=1;
    int j;
    while(i<1500001 && countprimes<n)
    {
        if(primes[i]==1)
        {
            i++;
            continue;
        }
        j=i*2;
        countprimes++;
        printf("%d ",i);
        if(countprimes==n)
            break;
        while(j<1500001)
        {
            primes[j]=1;
            j+=i;
        }
        i++;
    }
	return 0;
}
