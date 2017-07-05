#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int l,i,flag = 1;
        int a[27] = {0},b[27] = {0};
        char s[1010];
        scanf(" %s",s);
        l = strlen(s);
        for(i=0;i<l/2;i++)
        {
            a[s[i] - 97]++;
        }
        if(l%2 == 1)
        i = l/2 + 1;
        else
        i = l/2;
        while(i<l)
        {
            b[s[i] - 97]++;
            i++;
        }
        for(i=0;i<26;i++)
        {
            //printf(" %d %d",a[i],b[i]);
            if(a[i] != b[i])
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
