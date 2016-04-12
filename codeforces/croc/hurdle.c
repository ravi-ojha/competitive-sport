#include<stdio.h>
int main()
{
    int n,k;
    scanf(" %d %d",&n,&k);
    int count = 0;
    int flag = 0;
    char c;
    while(n--)
    {
        scanf(" %c",&c);
        if(c == '#')
        count++;
        else
        count = 0;
        if(count>=k)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
    return 0;
}
