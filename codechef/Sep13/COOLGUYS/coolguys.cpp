#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int tests;
    scanf(" %d",&tests);
    while(tests--)
    {
        long long t;
        scanf(" %lld",&t);
        long long count = 0;
        int i,j;
        for(j=1;j<=t;j++)
        {
            for(i=1;i*i<t;i++)
            {
                if(t%i == 0)
                {
                    count += 2;
                }
            }
            if(i*i == t)
            {
                count += 1;
            }
        }
        cout << count << endl;
    }
    return 0;
}
