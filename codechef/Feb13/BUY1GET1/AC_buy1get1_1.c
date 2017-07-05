#include<stdio.h>
#include<string.h>
main()
{
    int T;
    scanf(" %d",&T);
    while(T--)
    {
        int i,ans=0,sum=0;
        int bArr[52] = {0};
        char mystr[210];
        scanf(" %s",mystr);
        for(i=0;i<strlen(mystr);i++)
        {
            if (mystr[i] >= 97 && mystr[i] <= 122)
            {
                bArr[mystr[i]-97]++;
            }
            else if(mystr[i] >= 65 && mystr[i] <= 90)
            {
                bArr[mystr[i]-39]++;
            }
        }
        for(i=0;i<52;i++)
        {
            sum = (bArr[i]+1)/2;
            ans = ans + sum;
        }
        printf("%d\n",ans);
    }
    return 0;
}
