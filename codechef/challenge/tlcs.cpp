#include<cstdio>

void maxAndDirection(int lcs[][1001], int pos[][1001], int i, int j)
{
    if(lcs[i-1][j] >= lcs[i][j-1])
    {
        lcs[i][j] = lcs[i-1][j];
        pos[i][j] = 1;
    }
    else
    {
        lcs[i][j] = lcs[i][j-1];
        pos[i][j] = 3;
    }
}

int main()
{
    int t,p;
    scanf(" %d",&t);
    for(p=1;p<=t;p++)
    {
        int n, m, i, j;
        char s1[1001], s2[1001];
        int lcs[1001][1001];
        int pos[1001][1001] = {{0},{0}};
        scanf(" %d %s",&n,s1);
        scanf(" %d %s",&m,s2);
        //printf(" %s %s",s1,s2);
        for(i=0;i<1001;i++)
        {
            lcs[i][0] = 0;
        }
        for(j=0;j<1001;j++)
        {
            lcs[0][j] = 0;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                    pos[i][j] = 2;
                }
                else
                {
                    maxAndDirection(lcs,pos,i,j);
                }
            }
        }
//        for(i=0;i<=n;i++)
//        {
//            for(j=0;j<=m;j++)
//            {
//                printf("%3d",lcs[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n\n");
//        for(i=0;i<=n;i++)
//        {
//            for(j=0;j<=m;j++)
//            {
//                printf("%3d",pos[i][j]);
//            }
//            printf("\n");
//        }
        i = n;
        j = m;
        if(lcs[n][m] == 0)
        {
            printf("case %d N\n",p);
        }
        else
        {
            int xy[1001][2];
            char ans[1001];
            int an = 0, b;
            printf("case %d Y\n",p);
            printf("%d\n",lcs[n][m]);
            while(i>0 && j>0)
            {
                if(pos[i][j] == 2)
                {
                    //printf(" %c",s1[i-1]);
                    ans[an] = s1[i-1];
                    xy[an][0] = i;
                    xy[an][1] = j;
                    an++;
                    i -= 1;
                    j -= 1;
                }
                else if(pos[i][j] == 1)
                {
                    i -= 1;
                }
                else
                {
                    j -= 1;
                }
            }
            for(b=an-1;b>=0;b--)
            {
                printf("%c %d %d\n",ans[b],xy[b][0],xy[b][1]);
            }
        }
    }
    return 0;
}
