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
        int n,c,q,i,l,r;
        //scanf(" %d %d %d",&n,&c,&q);
        n = read();
        c = read();
        q = read();
        while(q--)
        {
            l = read();
            r = read();
            //scanf(" %d %d",&l,&r);
            if(c>=l && c<=r)
            c = l+r-c;
        }
        printf("%d\n",c);
    }
    return 0;
}
