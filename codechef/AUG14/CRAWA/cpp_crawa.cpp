#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int x, y;
        scanf(" %d %d",&x,&y);
        if( (y-x-1) <= 0 && (x+y-1) >= 0 )
        {
            if(x%2 == 1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else if( (y-x-1) >= 0 && (x+y) >= 0 )
        {
            if(y%2 == 0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else if( (x-y) <= 0 && (x+y) <= 0 )
        {
            int p_x = (-1)*x;
            if(p_x%2 == 0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else if( (x-y) >= 0 && (x+y-1) <= 0 )
        {
            int p_y = (-1)*y;
            if(p_y%2 == 0)
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