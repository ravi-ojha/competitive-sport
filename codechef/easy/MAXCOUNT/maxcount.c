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
        int n,max=0,m=0,i,z,j;
        int a[10001] = {0};
        //scanf(" %d",&n);
        n = read();
        for(j=0;j<n;j++)
        {
            //scanf(" %d",&z);
            z = read();
            a[z]++;
        }
        for(i=0;i<10001;i++)
        {
            if(a[i]>max)
            {
                max = a[i];
                m = i;
            }
        }
        printf("%d %d\n",m,max);
    }
    return 0;
}
