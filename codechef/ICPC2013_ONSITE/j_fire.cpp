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
        double a,b;
        scanf(" %lf %lf",&a,&b);
        double res = 0;
        if(a>b)
        {
            res = sqrt(3)*a*max(a/2+b,a)/2;
        }
        else
        {
            res = sqrt(3)*b*max(b/2+a,b)/2;
        }
        printf("%.3lf\n",res);
    }
    return 0;
}
