#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    int i;
        char c;
    scanf(" %d",&T);
    char a[27],b[27];
        for(i=0;i<26;i++)
        {
            scanf(" %c",&c);
            a[i] = c;
            b[i] = c-32;
        }
    while(T--)
    {


//        for(i=0;i<26;i++)
//        {
//            printf("%c %c\n",a[i],b[i]);
//        }
        int l,j;
        char str[120],ans[120];
        scanf(" %s",str);
        l = strlen(str);
        int  k = 0;
        for(j=0;j<l;j++)
        {
            if(str[j]>=65 && str[j]<=90)
            {
                //printf("%c",b[str[j]-65]);
                ans[k] = b[str[j]-65];
                k++;
            }
            else if(str[j] == '_')
            {
                ans[k] = ' ';
                k++;
            }
            else if(str[j]>=97 && str[j]<=122)
            {
                ans[k] = a[str[j]-97];
                k++;
            }
            else
            {
                ans[k] = str[j];
                k++;
            }
        }
        int p;
        for(p=0;p<k;p++)
        {
            printf("%c",ans[p]);
        }
        printf("\n");
    }
    return 0;
}
