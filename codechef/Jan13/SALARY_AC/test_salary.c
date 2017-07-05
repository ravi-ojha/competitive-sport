#include<stdio.h>
int main()
{
    int i,j,k,m,n,stepCount=0;
    int T, N;
    int count = 0;
    scanf(" %d",&T);
    scanf(" %d",&N);
    int W[T][N];
    for(i=0; i<N; i++)
    {
        scanf(" %d",&W[0][i]);
    }
    /*printf("Just to confirm\n");
    for(i=0; i<N; i++)
    {
        printf(" %d",W[0][i]);
    }*/
    while(1)
    {
        count = 0;
        for (i=0; i<N; i++)
        {
            if (W[0][0] == W[0][i])
                {
                    count++;
                }
                //printf(" Count = %d",count);
        }
        if (count == N)
        {
            printf("\nFinally\n");
            for(i=0; i<N; i++)
            {
                printf(" %d",W[0][i]);
            }
            printf("\nNumber of Steps taken: %d",stepCount);
            return 0;
        }
        m = W[0][0];
        n = 0;
        for(i=0; i<N; i++)
        {
            if (m<W[0][i])
            {
                m = W[0][i];
                n = i;
            }
        }
        //printf("Value so n: %d\n",n);
        for(i=0; i<N; i++)
        {
            if(i == n)
            {
                continue;
            }
            W[0][i] = W[0][i] + 1;
        }
        stepCount++;
        /*printf("\nAgain Just to confirm\n");
        for(i=0; i<N; i++)
        {
            printf(" %d",W[0][i]);
        }*/
    }

}
