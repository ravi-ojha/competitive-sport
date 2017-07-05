#include<stdio.h>
#include<string.h>
int main()
{
    int t,i;
    scanf(" %d",&t);
//    for(i=0;i<26;i++)
//        {
//            printf("%5c",i+97);
//        }
//        printf("\n");
    while(t--)
    {
        int flag = 1,i,p,j;
        int parent[30] = {0};
        char s1[50001],s2[50001];
        int n,l1,l2,l;
        scanf(" %s",s1);
        scanf(" %s",s2);
        for(i=0;s1[i]!='\0';i++)
        {
            parent[s1[i]-'a']++;
        }
        for(i=0;s2[i]!='\0';i++)
        {
            parent[s2[i]-'a']++;
        }
//        for(i=0;i<30;i++)
//        {
//            printf("%5d",parent[i]);
//        }
        scanf(" %d",&n);
        char c[50001];
        i = 0;
        gets(c);
        while(i<n)
        {
            gets(c);
            j=0;
            i++;
            //l = strlen(c);
            while(c[j] != '\0')
            {
                if(parent[c[j]-'a'] <= 0)
                {
                    flag = 0;
                    //i++;
                    while(i<n)
                    {
                        scanf(" %s",c);
                        i++;
                    }
                    goto hell;
                }
                else
                {
                    parent[c[j]-'a']--;
                }
                j++;
            }
            //i++;
        }
        hell:
        if(flag==0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
