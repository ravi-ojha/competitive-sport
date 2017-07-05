#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,k,i;
        scanf(" %d %d",&n,&k);
        int a[n];
        int even_cnt = 0;
        int odd_cnt = 0;
        for(i=0;i<n;i++)
        {
            scanf(" %d",&a[i]);
            if(a[i]&1)
            {
                odd_cnt++;
            }
        }
        even_cnt = n - odd_cnt;
        if(k == 0)
        {
            if(odd_cnt > 0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            if(k <= even_cnt)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}