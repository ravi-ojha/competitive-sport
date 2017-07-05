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
    int t,n,i,j;
    n = read();
    while(n)
    {
        int a[100001],b[100001];
        int flag = 0;
        t = n;
        for(i=1;i<=t;i++)
        {
            a[i] = read();
            b[a[i]] = i;
        }

        for(j=1;j<=t;j++)
        {
            //printf("a[%d] = %d\t",j,a[j]);
            //printf("b[%d] = %d\n",j,b[j]);
            if(a[j] != b[j])
            {
                flag = 1;
                puts("not ambiguous");
                break;
            }
        }
        if(flag == 0)
        {
            puts("ambiguous");
        }
        n = read();
    }
    return 0;
}
