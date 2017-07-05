#include<stdio.h>
#include<string.h>
int main()
{
    int a[26] = {1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
    int T;
    scanf(" %d",&T);
    while(T--)
    {
        int l,sum = 0,i;
        char mystr[101];
        //gets(mystr);
        scanf(" %s",mystr);
        //l = strlen(mystr);
        for(i=0;i<strlen(mystr);i++)
        {
            sum = sum + a[mystr[i]-65];
        }
        printf("%d\n",sum);
    }
    return 0;
}
