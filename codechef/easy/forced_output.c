#include<stdio.h>
#include<string.h>
main()
{
    int T;
    char ynoutput[10];
    scanf(" %d",&T);
    int a[100][100],b[100];
    int i,j,m,l,k,p=0,count;
    for(i=0;i<T;i++)
    {
        for(j=0;j<T;j++)
        {
            scanf(" %s",ynoutput);
            //printf("check");
            if(strcmp(ynoutput,"NO")==0)
            {
                a[i][j] = 0;
            }
            else
            {
                a[i][j] = 1;
            }
        }
    }
    for(i=0;i<T;i++)
    {
        for(j=0;j<T;j++)
        {
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<T;i++)
    {
        p=0;
        count = 0;
        if(a[i][i] == 1)
        {
            for(j=i;j<T;j++)
            {
                if(a[i][j]==1)
                {
                    b[p] = j;
                    p++;
                }
            }
            for(k=1;k<p;k++)
            {
                for(m=0;m<p;m++)
                {
                    //printf("a[b[k]]=%d",a[])
                    if(a[b[k]][b[m]]==1)
                    count++;
                    else
                    break;
                }
            }
            if(count == p*(p-1))
            break;
            else
            continue;
        }
    }
    printf("\n\nArray b:\n");
    for(l=0;l<p;l++)
    {
        printf("%5d",b[l]);
    }
    printf("\n\nFinal ans is: \n");
    for(l=0;l<T;l++)
    {
        printf("%5d",a[i][l]);
    }
    printf("\n");
}
