#include<stdio.h>
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int i,j,m,n,from;
        int ourRange[111111];

        scanf(" %d",&n);

        int z;
        for(i=0;i<=n;i++)
        {
            ourRange[i] = i;
        }
        ourRange[0] = 0;
        ourRange[1] = 0;
        for(i=2;i*i<n;i++)
        {
            for(j=i,z=0;j<=n;j=j+i,z++)
            {
                if(j!=i)
                ourRange[j] = 0;
            }
        }
        if(m==1)
        {
            ourRange[0] = 0;
        }
        for(i=0;i<z;i++)
        {
            if(ourRange[i])
            {
                printf("%d\n",ourRange[i]);
            }
        }
    }
    return 0;
}
