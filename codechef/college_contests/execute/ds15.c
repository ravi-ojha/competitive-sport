#include<stdio.h>
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
int main()
{
    int T;
    T = fast_int();
    while(T--)
    {
        int n,m,sum=0,i;
        n = fast_int();
        m = n/2;
        for(i=1;i<=m;i++)
        {
            if(n%i == 0)
            {
                sum = sum+i;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
