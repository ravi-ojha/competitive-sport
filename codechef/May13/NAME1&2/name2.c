#include<stdio.h>
#include<string.h>
int solve(char s1[],char s2[],int l1,int l2)
{
    int i=0;
    int j=0;
    while(i<l1 && j<l2)
    {
        if(s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    if(i == l1)
    return 1;
    else
    return 0;
}
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int l1, l2,flag;
        char s1[30000],s2[30000];
        scanf(" %s",s1);
        scanf(" %s",s2);
        l1 = strlen(s1);
        l2 = strlen(s2);
        if(l1 > l2)
        {
            flag = solve(s2,s1,l2,l1);
        }
        else
        {
            flag = solve(s1,s2,l1,l2);
        }
        if(flag&1)
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}
