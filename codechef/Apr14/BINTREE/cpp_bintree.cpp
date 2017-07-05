#include<cstdio>
#include<iostream>
using namespace std;
inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
     neg = 1;
     c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
     x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
     x = -x;
}
int main()
{
    int n;
    fastRead_int(n);
    while(n--)
    {
        int x,y;
        int xdis = 0;
        int ydis = 0;
        //scanf(" %d %d",&x,&y);
        fastRead_int(x);
        fastRead_int(y);
        while(x!=y)
        {
            while(x>y)
            {
                x /= 2;
                xdis++;
            }
            if(x == y)
            {
                break;
            }
            while(x<y)
            {
                y /= 2;
                ydis++;
            }
        }
        printf("%d\n",xdis+ydis);
    }
    return 0;
}
