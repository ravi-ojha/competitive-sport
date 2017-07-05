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
    int T;
    T = read();
    while(T--)
    {
        int a[200],i,j,n,k;
        a[0] = 1;
        //a[1] = 5;
        int m = 1;
        n = read();
        int temp = 0;
        for(k=2;k<=n;k++)
        {
            for(i=0;i<m;i++)
            {
                temp = a[i]*k + temp;
                //printf("temp = %d\n",temp);
                a[i] = temp%10;
                //printf("a[%d] = %d\n",i,a[i]);
                temp = temp/10;
            }
            while(temp!=0)
            {
                //printf("temp = %d\n",temp);
                a[i] = temp%10;
                //printf("a[%d] = %d\n",i,a[i]);
                temp /= 10;
                i++;
            }
            m = i;
        }
        for(j=i-1;j>=0;j--)
        {
            printf("%d",a[j]);
        }
        printf("\n");
    }
    return 0;
}
