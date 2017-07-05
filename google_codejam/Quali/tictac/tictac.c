#include<stdio.h>
int main()
{
    int t,p,i,j,k;
    scanf(" %d",&t);
    for(p=1;p<=t;p++)
    {
        char a[4][4];
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                scanf(" %c",&a[i][j]);
            }
        }
        int dots = 0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                //printf(" %c",a[i][j]);
                if(a[i][j] == '.')
                {
                    dots++;
                }
            }
            //printf("\n");
        }
        int Xcount = 0,Ocount=0;
        int Xwon = 0, Owon = 0;
        for(j=0;j<4;j++)
        {
            Xcount = 0;
            Ocount = 0;
            for(k=0;k<4;k++)
            {
                if(a[k][j] == 'X' || a[k][j] == 'T')
                {
                    Xcount++;
                }
                if(a[k][j] == 'O' || a[k][j] == 'T')
                {
                    Ocount++;
                }
            }
            //printf("Xcount = %d  Ocount = %d\n",Xcount,Ocount);
            if(Xcount == 4)
            {
                Xwon = 1;
            }
            if(Ocount == 4)
            {
                Owon = 1;
            }
        }
        for(j=0;j<4;j++)
        {
            Xcount = 0;
            Ocount = 0;
            for(k=0;k<4;k++)
            {
                if(a[j][k] == 'X' || a[j][k] == 'T')
                {
                    Xcount++;
                }
                if(a[j][k] == 'O' || a[j][k] == 'T')
                {
                    Ocount++;
                }
            }
            //printf("Xcount = %d  Ocount = %d\n",Xcount,Ocount);
            if(Xcount == 4)
            {
                Xwon = 1;
            }
            if(Ocount == 4)
            {
                Owon = 1;
            }
        }
        Xcount = 0;
        Ocount = 0;
        for(i=0,j=0;i<4;i++,j++)
        {
            if(a[i][j] == 'X' || a[i][j] == 'T')
            {
                Xcount++;
            }
            if(a[i][j] == 'O' || a[i][j] == 'T')
            {
                Ocount++;
            }
        }
        //printf("Xcount = %d  Ocount = %d\n",Xcount,Ocount);
        if(Xcount == 4)
        {
            Xwon = 1;
        }
        if(Ocount == 4)
        {
            Owon = 1;
        }
        Xcount = 0;
        Ocount = 0;
        for(i=0,j=3;i<4;i++,j--)
        {
            if(a[i][j] == 'X' || a[i][j] == 'T')
            {
                Xcount++;
            }
            if(a[i][j] == 'O' || a[i][j] == 'T')
            {
                Ocount++;
            }
        }
        //printf("Xcount = %d  Ocount = %d\n",Xcount,Ocount);
        if(Xcount == 4)
        {
            Xwon = 1;
        }
        if(Ocount == 4)
        {
            Owon = 1;
        }
        if(Xwon == 1 && Owon == 1)
        {
            printf("Case #%d: Draw\n",p);
        }
        if(Xwon == 0 && Owon == 1)
        {
            printf("Case #%d: O won\n",p);
        }
        if(Xwon == 1 && Owon == 0)
        {
            printf("Case #%d: X won\n",p);
        }
        if(Xwon == 0 && Owon == 0)
        {
            if(dots>0)
            {
                printf("Case #%d: Game has not completed\n",p);
            }
            else
            {
                printf("Case #%d: Draw\n",p);
            }
        }
    }
    return 0;
}
