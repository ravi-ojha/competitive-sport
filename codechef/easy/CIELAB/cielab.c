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
    int a,b;
    a = read();
    b = read();
    a -= b;
    if(a%10 == 9)
    {
        printf("%d",a-1);
        return 0;
    }
    else
    {
        printf("%d",a+1);
        return 0;
    }
}
