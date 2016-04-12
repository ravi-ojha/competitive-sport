#include<stdio.h>
int main()
{
    int n,k,K,J,i,j,p,l;
    scanf(" %d %d",&n,&k);
    char a[n+1];
    if(k>n)
    {
        printf("-1\n");
        return 0;
    }
    if(k == 1 && n>1)
    {
        printf("-1");
        return 0;
    }
    if(n==1)
    {
        printf("a\n");
        return 0;
    }
    if(n==2)
    {
        printf("ab\n");
        return 0;
    }
//    if(n==26 && n==25)
//    {
//        printf("abacdefghijklmnopqrstuvwxy\n");
//    }
    {
        K = k-2;
        J = n - K;
        for(i=0;i<J;i++)
        {
            if(i%2 == 0)
            {
                a[i] = 'a';
            }
            else
            a[i] = 'b';
        }
        for(l=0,j=i,p=99;l<K;j++,p++,l++)
        {
            a[j] = p;
        }
        a[j] = '\0';
        printf("%s\n",a);
    }
    return 0;
}
