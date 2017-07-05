#include<stdio.h>
int main()
{
	int i,n,d,ans,t;
	int a[1000000];
	n = 103993;
	d = 33102;
	t = n%d;
    for(i=0;i<1000000;i++)
    {
        t = t*10;
        ans = t/d;
        t = t%d;
        //printf("%d",ans);
        a[i] = ans;
    }
    int T,K;
    scanf(" %d",&T);
    while(T--)
    {
        scanf(" %d",&K);
        if(K == 0)
        {
            printf("3\n");
        }
        else
        {printf("3.");
        for(i=0;i<K;i++)
        {
            printf("%d",a[i]);
        }
        printf("\n");}
    }
    return 0;
}

