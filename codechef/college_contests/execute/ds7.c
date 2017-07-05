#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf(" %d",&T);
    while(T--)
    {
        int m,i,j,n,k,l;
        char msg[202];
        scanf(" %d",&m);
        scanf(" %s",msg);
        n = strlen(msg)/m;
        char iAns[201][201];
        for(i=0;i<n;i++)
        {
            if(i&1)
            {

                l = 0;
                for(j=(i+1)*m-1;l<m;j--,l++)
                {iAns[i][l] = msg[j];}
            }
            else
            {
                k = 0;
                for(j=i*m;k<m;j++,k++)
                {iAns[i][k] = msg[j];}
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                //fAns[k] = iAns[j][i];
                printf("%c",iAns[j][i]);
            }
        }
        printf("\n");
    }
    return 0;
}
