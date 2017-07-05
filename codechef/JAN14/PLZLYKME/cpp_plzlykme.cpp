#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        double l,d,s,c;
        scanf(" %lf %lf %lf %lf",&l,&d,&s,&c);
        //printf("%lf\n",log(c+1));
        //double temp = l/s;
        if(log10(l) <= (log10(s) + (d-1)*log10(c+1)))
        {
            printf("ALIVE AND KICKING\n");
        }
        else
        {
            printf("DEAD AND ROTTING\n");
        }
    }
    return 0;
}
