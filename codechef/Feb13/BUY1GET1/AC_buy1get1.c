#include<stdio.h>
#include<string.h>

int main()
{
    int T;
    scanf(" %d",&T);
    while(T--)
    {
        int i,count = 0;
        int b[255] = {0};
        char s[201];
        scanf(" %s",s);
        for(i=0;i<strlen(s);i++)
        {
            //printf("\ns[%d] = %d",i,s[i]);
            if(b[s[i]] == 0)
                {
                    //printf("\nb[%d] = %d",s[i],b[s[i]]);
                    b[s[i]]++;
                    //printf("\nb[%d] = %d",s[i],b[s[i]]);
                    count++;
                }
            else
                {
                    //printf("\nb[%d] = %d",s[i],b[s[i]]);
                    b[s[i]] = 0;
                    //printf("\nb[%d] = %d",s[i],b[s[i]]);
                }
        }
        printf("%d\n",count);
    }
    return 0;
}
