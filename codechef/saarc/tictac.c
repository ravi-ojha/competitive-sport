#include<stdio.h>
int main()
{
    int T,i,j,k,l;
    scanf(" %d",&T);
    while(T--)
        {
            int Awin = 0;
            int Bwin = 0;
            char a[5][5],ch;
            for(i=0;i<5;i++)
            {
                for(j=0;j<5;j++)
                    scanf(" %c",&a[i][j]);
            }
//            for(i=0;i<5;i++)
//            {
//                for(j=0;j<5;j++)
//                printf(" %c",a[i][j]);
//                printf("\n");
//            }
int count = 0;
            for(i=0;i<5;i++)
            {
                for(j=0;j<5;j++)
                {
                    count = 0;
                    ch = a[i][j];
                    if(ch == 'A' && Awin == 1)
                    continue;
                    else if(ch == 'B' && Bwin == 1)
                    continue;
                    if(Awin == 1 && Bwin == 1)
                    goto hell;
                    for(k=(j+1);k<(j+3) && k<5;k++)
                    {
                        if(ch == a[i][k])
                        count++;
                    }
                    if(count == 2)
                    {
                        if (ch == 'A')
                        Awin = 1;
                        else
                        Bwin = 1;
                        continue;
                        //count = 0;
                    }
                    count = 0;
                    for(k=(i+1);k<(i+3) && k<5;k++)
                    {
                        if(ch == a[k][j])
                        count++;
                    }
                    if(count == 2)
                    {
                        if (ch == 'A')
                        Awin = 1;
                        else
                        Bwin = 1;
                        continue;
                        //count = 0;
                    }
                    count = 0;
                    for(l=(i+1),k=(j+1);k<(j+3) && k<5 && l<(i+3) && l<5;k++,l++)
                    {
                        if(ch == a[l][k])
                        count++;
                    }
                    if(count == 2)
                    {
                        if (ch == 'A')
                        Awin = 1;
                        else
                        Bwin = 1;
                        continue;
                        //count = 0;
                    }
                    count = 0;
                    //count = 0;
                    for(l=(i+1),k=(j-1);k>(j-3) && k>=0 && l<(i+3) && l<5;k--,l++)
                    {
                        if(ch == a[l][k])
                        count++;
                    }
                    if(count == 2)
                    {
                        if (ch == 'A')
                        Awin = 1;
                        else
                        Bwin = 1;
                        continue;
                        //count = 0;
                    }
                    count = 0;
                }
            }
            hell:
            if(Awin == 1 && Bwin == 1)
            {
                printf("draw\n");
            }
            else if(Awin == 1 && Bwin == 0)
            {
                printf("A wins\n");
            }
            else if(Awin == 0 && Bwin == 1)
            {
                printf("B wins\n");
            }
            else if(Awin == 0 && Bwin == 0)
            {
                printf("draw\n");
            }
        }
    return 0;
}
