#include<stdio.h>
int main()
{
    int C,S;
    int p,t,i,j;
    int c[201] = {0};
    int s[201][1001] = {{0},{0}};
    scanf(" %d %d",&C,&S);
    for(i=0;i<S;i++)
    {
        scanf(" %d",&p);
        for(j=0;j<p;j++)
        {
            scanf(" %d",&t);
            s[t][c[t]] = i;
            c[t]++;
        }
    }
//    for(i=0;i<C;i++)
//    {
//        printf(" %d",c[i]);
//    }
//    printf("\n");
//    for(i=0;i<C;i++)
//    {
//        for(j=0;j<S;j++)
//        {
//            printf(" %d",s[i][j]);
//        }
//        printf("\n");
//    }
    int l = 999999;
    int min = 999999;
    for(i=0;i<C;i++)
    {
        if(l>c[i])
        {
            l = c[i];
            min = i;
        }
    }
    printf("%d\n",l);
    for(i=0;i<l;i++)
    {
        printf("%d\n",s[min][i]);
    }
    return 0;
}
