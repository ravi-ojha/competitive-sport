#include<stdio.h>
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int i,j,m,n,from;
        int ourRange[111111];

        scanf(" %d %d",&m,&n);
        int z;
        for(i=m,z=0;i<=n;i++,z++)
        {
            ourRange[z] = i;
        }
        for(i=2;i*i<n;i++)
        {
            from = m/i;
            from*=i;
            for(j=from;j<=n;j=j+i)
            {
                if(j!=i && j>=m)
                ourRange[j-m] = 0;
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
