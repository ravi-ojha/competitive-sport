int fast_int()
{
        int n = 0;
        char c = getchar();
        while (!('0' <= c && c <= '9'))
        {
            c = getchar();
        }
        while ('0' <= c && c <= '9')
        {
            n = (n<<3)+(n<<1) + c - '0';
            c = getchar();
        }
        return n;
}


long int read()
{
    long int _n = 0;
    char p = getchar_unlocked();
    for(;p<33;) { p = getchar_unlocked(); }
    while(p>32)
    {
        _n = (_n<<3) + (_n<<1) + (p-'0');
        p = getchar_unlocked();
    }
    return _n;
}

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

inline int readInt()
{
int n=0;
char c;
while(1)
{
c=getchar_unlocked();
if(c=='\n'||c==' ')
break;
n=n*10+c-'0';
}
return n;
}

inline void writeInt(int n)
{
int i=10;
char buf[11];
buf[10]='\0';
do//while loop is not used becuase do...while will handle the case when n is 0 by default
{
buf[--i]=(n%10)+'0';
n/=10;
}while(n);
while(buf[i])
{
putchar_unlocked(buf[i]);
i++;
}
}
