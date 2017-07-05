#include<stdio.h>
//int fast_int()
//{
//        int n = 0;
//        char c = getchar_unlocked();
//        while (!('0' <= c && c <= '9'))
//        {
//            c = getchar_unlocked();
//        }
//        while ('0' <= c && c <= '9')
//        {
//            n = (n<<3)+(n<<1) + c - '0';
//            c = getchar_unlocked();
//        }
//        return n;
//}
//long int read()
//{
//    long int _n = 0;
//    char p = getchar_unlocked();
//    for(;p<33;) { p = getchar_unlocked(); }
//    while(p>32)
//    {
//        _n = (_n<<3) + (_n<<1) + (p-'0');
//        p = getchar_unlocked();
//    }
//    return _n;
//}
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
    int T, k, p, count = 0;
    T = read();
    k = read();
    while(T--)
    {
        //count = 0;
        p = read();
        if(p%k == 0)
        count++;
    }
    printf("%d\n",count);
    return 0;
}
