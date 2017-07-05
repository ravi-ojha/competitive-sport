#include<stdio.h>
int main()
{
    int N,p;
    int a[26] = {2,22,222,3,33,333,4,44,444,5,55,555,6,66,666,7,77,777,7777,8,88,888,9,99,999,9999};
    scanf(" %d",&N);
    for(p=1;p<=N;p++)
    {
        int i,m=0;
        char mystr[1010];
        scanf(" %[^\n]",mystr);
        printf("Case #%d: ",p);
        for(i=0;mystr[i]!='\0';i++)
        {
            if(mystr[i] == ' ')
            {
                if(m==1)
                {
                    printf(" 0");
                }
                else
                {
                    printf("0");
                    m = 1;
                }
            }
            else
            {
                if(a[mystr[i]-97]%10 == m)
                {
                    printf(" %d",a[mystr[i]-97]);
                }
                else
                {
                    printf("%d",a[mystr[i]-97]);
                    m = a[mystr[i]-97]%10;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
