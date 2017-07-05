#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
long long factArray[10000001];
int main()
{
    int n,m;
    scanf(" %d",&n);
    scanf(" %d",&m);
    //printf("Error");
    long long p[n],equi[n],f[n],res=0;
    //printf("Error");

    factArray[0]=1;
    factArray[1]=1;
   // printf("Error");
    for(int i=2;i<10000001;i++)
    {
        factArray[i]=(factArray[i-1]*i)%m;
    }
    //printf("Error");
    for(int i=0;i<n;i++)
    {
        scanf(" %lld",&p[i]);
        equi[i]=(p[i]*p[i]*(p[i]+1)/2);

        if(p[i]%2 == 1)
        {
            equi[i] = (p[i]+1)/2;
            equi[i] = ((((equi[i]%m)*(p[i]%m))%m)*(p[i]%m))%m;
        }
        else
        {
            equi[i] = p[i]/2;
            equi[i] = ((((equi[i]%m)*((p[i]+1)%m))%m)*(p[i]%m))%m;
        }

        if(p[i]+1>=m)
            f[i]=-1+m;
        else
        {
            f[i]=factArray[p[i]+1]-1;
        }

        //f[i]=factWMod((p[i]+1),m)-1;
        //printf("%lld %lld\n",equi[i],f[i]);
        res+=(equi[i]+f[i])%m;
    }
    printf("%lld\n",res%m);
    return 0;
}
