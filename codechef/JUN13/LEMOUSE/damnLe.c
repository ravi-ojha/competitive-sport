#include<stdio.h>

int read()
{
    int _n = 0;
    char p = getchar_unlocked();
    for(;p<33;) { p = getchar_unlocked(); }
    while(p>32)
    {
        _n = (_n<<3) + (_n<<1) + (p-'0');
        p = getchar_unlocked();
    }
    return _n;
}

int main()
{
    int t;
    //scanf(" %d",&t);
    t = read();
    while(t--)
    {
        int n,m;
        int a[111][111];
        int b[111][111];
        int c[111][111];
        int i,j;
        int t1,t2;
        char temp[111];
        //scanf(" %d %d",&n,&m);
        n = read();
        m = read();
        for(i=0;i<n;i++)
        {
            scanf(" %s",temp);
            for(j=0;j<m;j++)
            {
                if(temp[j]=='0')
                a[i][j]=0;

                if(temp[j]=='1')
                {a[i][j]=1;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            a[i][m]=0;
        }
        for(i=0;i<m;i++)
        {
            a[n][i]=0;
        }

        b[0][0]= a[0][0]+ a[1][0]+ a[0][1];

        for(i=1;i<m-1;i++)
        {
            b[0][i]= b[0][i-1] + a[1][i]+ a[0][i+1];
            c[0][i]= 1;
        }
        b[0][m-1]= b[0][m-2]+ a[1][m-1];
        c[0][m-1]=1;

        for(i=1;i<n-1;i++)
        {
            b[i][0]= b[i-1][0] + a[i+1][0]+ a[i][1];
            c[i][0]= 2;
        }
        b[n-1][0]= b[n-2][0] + a[n-1][1];
        c[n-1][0]=2;

        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                if(c[i][j-1]== 1)
                {
                    t1= b[i][j-1]+ a[i+1][j]+ a[i-1][j]+ a[i][j+1];
                }
                else
                {
                    t1= b[i][j-1]+ a[i+1][j]+ a[i][j+1];
                }

                if(c[i-1][j]== 2)
                {
                    t2= b[i-1][j]+ a[i][j+1]+ a[i+1][j] + a[i][j-1];
                }
                else
                {
                    t2= b[i-1][j] + a[i][j+1]+ a[i+1][j];
                }
                if(t1<t2)
                {
                    b[i][j]= t1;
                    c[i][j]=1;
                }
                if(t2<t1)
                {
                    b[i][j]= t2;
                    c[i][j]= 2;
                }
                if(t2==t1)
                {
                    b[i][j]=t1;
                    c[i][j]=3;
                }
            }
        }
        printf("%d\n",b[n-1][m-1]);
    }
    return 0;
}
