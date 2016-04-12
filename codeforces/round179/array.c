#include<stdio.h>
int main()
{
    int n;
    scanf(" %d",&n);
    int a[n];
    int b[100] = {0};
    for(i=0;i<n;i++)
    {
        scanf(" %d",&a[i]);
    }
    if(n==1)
    {
        printf("YES\n");
        return 0;
    }
    if(n==2 && (a[0] != a[1]))
    {
        printf("YES\n");
        return 0;
    }
    else
    {
        printf("NO\n");
        return 0;
    }
//    if(n==3)
//    {
//        if((a[0] == a[1]) && (a[0] == a[2]))
//        {
//            printf("NO\n");
//            return 0;
//        }
//    }
    if((a[0] == a[1]) && (a[0] == a[2]))
    {
        printf("NO\n");
        return 0;
    }
    if((a[n-1] == a[n-2]) && (a[n-1] == a[n-3]))
    {
        printf("NO\n");
        return 0;
    }
`   for(i=0;i<n;i++)
    {

    }

}
