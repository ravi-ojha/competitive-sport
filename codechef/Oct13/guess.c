#include<stdio.h>
int main()
{
    int t,g[10];
    int a[100];
    int n,s=0,e=0;
    int count=0;
    int i=0,j=0;
    int k=0;

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        k=0;

        do
        {
            scanf("%d",&a[k]);
            k++;

        }while(a[k-1]!=0);

        s=1;
        e=n;

        for(j=0;a[j]!=0;j++)
        {
            if(a[j]==-1)
            {

                e=((s+e)/2)-1;
            }
            else if(a[j]==1)
            {
                s=((s+e)/2)+1;

            }

        }

                g[i]=(e+s)/2;
    }


    for(i=1;i<=t;i++)
    {
        printf("%d\n",g[i]);
    }
return 0;
}
