#include<stdio.h>
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int i;
        int jewelFreq[255] = {0};
        int result = 0;
        char jewel[111];
        char stone[111];
        scanf(" %s",jewel);
        scanf(" %s",stone);
        for(i=0;jewel[i]!='\0';i++)
        {
            jewelFreq[jewel[i]]++;
        }
        for(i=0;stone[i]!='\0';i++)
        {
            if(jewelFreq[stone[i]]!=0)
            result++;
        }
        printf("%d\n",result);
    }
    return 0;
}
