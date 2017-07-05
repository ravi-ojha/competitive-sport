#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    scanf(" %d",&n);
    for(i=1;i<=n;i++)
    {
        int m,j,k,l,p=0;
        char mystr[1100],ans[1100];
        scanf(" %[^\n]",mystr);
        l = strlen(mystr);
        for(j=l-1;j>=0;j--)
        {
            m = j;
            while(mystr[j] != ' ' && j>=0)
            {
                j--;
            }
            k=j;
            k++;
            while(k<=m)
            {
                ans[p] = mystr[k];
                p++;
                k++;
            }
            ans[p] = ' ';
            p++;
            //puts(ans);
        }
        ans[p] = '\0';
        printf("Case #%d: ",i);
        puts(ans);
    }
    return 0;
}
