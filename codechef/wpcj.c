#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        char s1[111111], s2[111111];
        scanf(" %s %s",s1,s2);
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        if(l1>l2)
        {
            if(strstr(s2, s1) != NULL)
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
            if(strstr(s1, s2) != NULL)
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
