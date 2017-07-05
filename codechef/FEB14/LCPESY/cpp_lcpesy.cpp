#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int t;
    scanf(" %d",&t);
    char a[11111],b[11111];
    while(t--)
    {

        int freqA[200] = {0};
        int freqB[200] = {0};
        int i,res=0;
        scanf(" %s %s",a,b);
        int lenA = strlen(a);
        int lenB = strlen(b);
        for(i=0;i<lenA;i++)
        {
            freqA[a[i]]++;
        }
        for(i=0;i<lenB;i++)
        {
            freqB[b[i]]++;
        }
        for(i=0;i<200;i++)
        {
            res += min(freqA[i],freqB[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}
