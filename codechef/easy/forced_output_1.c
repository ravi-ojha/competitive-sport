#include<stdio.h>
#include<string.h>
int main()
{
    int T,c,x,y,r;
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
        c=0;
        p=0;
        count = 0;
        if(a[i][i] == 1)
        {
            for(j=0;j<T;j++)
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
                for(x=0;x<T;x++)
                {
                    //printf("\nx is %d",x);
                    c = 0;
                    for(r=0;r<p;r++)
                    {

                        if(x==b[r])
                        {
                            //printf("\nhere\n");
                            goto here;
                        }

                    }

                    if(a[x][i]==1)
                    {
                        for(y=0;y<T;y++)
                        {
                            if(a[x][y] == a[i][y])
                            c++;
                        }
                    }
//                    printf("\nc is %d",c);
                    if(c==T)
                    {
                        //printf("c is %d & T is %d",c,T);
                        goto direct;
                    }
                    here:
                    continue;
                }

            if(count == p*(p-1))
            {
//                printf("i is %d\n",i);
//                printf("check\n");
                break;
            }

            else
            continue;
            direct:
            continue;
        }
    }
//    printf("\n\nArray b:\n");
//    for(l=0;l<p;l++)
//    {
//        printf("%5d",b[l]);
//    }
//    printf("\n\nInitial Input\n");
//    for(k=0;i<T;k++)
//    {
//        for(j=0;j<T;j++)
//        {
//            printf("%5d",a[k][j]);
//        }
//        printf("\n");
//    }
//    printf("\n\nFinal ans is: \n");
    i = b[p-1];
//    printf("\ni is %d\n",i);
    for(l=0;l<T;l++)
    {
        if(a[i][l] == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
