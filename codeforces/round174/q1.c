#include<stdio.h>
int main()
{
    int n,countAI=0,countI=0,i;
    char ch,myStr[200001];
    scanf(" %d",&n);
    scanf(" %s",myStr);
    for(i=0;i<n;i++)
    {
        ch = myStr[i];
        if(ch == 'I')
        {
            countI++;
            continue;
        }
        else if(ch != 'F')
        {
            countAI++;
        }
    }
    if(countI == 0)
    {
        printf("%d\n",countAI);
    }
    else
    {
        printf("%d\n",countI);
    }
    return 0;
}
