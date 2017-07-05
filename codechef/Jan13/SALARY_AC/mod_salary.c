
#include<stdio.h>
int main()
{
    int i,j,k,m,n,stepCount=0;
    int T, N;
    int W[100][100];
    int count = 0;
    scanf(" %d",&T);
    for(j=0; j<T; j++)
    {
        scanf(" %d",&N);
        for(i=0; i<N; i++)
        {
            scanf(" %d",&W[j][i]);
        }
        /*printf("Just to confirm: ");
        for(i=0; i<N; i++)
        {
            printf(" %d",W[j][i]);
        }
        printf("\n");*/

        stepCount = 0;
        while(1)
        {
            count = 0;
            for (i=0; i<N; i++)
            {
                if (W[j][0] == W[j][i])
                    {
                        count++;
                    }
                    //printf(" Count = %d",count);
            }
            if (count == N)
            {
                /*printf("\nFinally\n");
                for(i=0; i<N; i++)
                {
                    printf(" %d",W[j][i]);
                }*/
                printf("%d",stepCount);
                //return 0;
                break;
            }
            m = W[j][0];
            n = 0;
            for(i=0; i<N; i++)
            {
                if (m<W[j][i])
                {
                    m = W[j][i];
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
                W[j][i] = W[j][i] + 1;
            }
            stepCount++;
            /*printf("\nAgain Just to confirm\n");
            for(i=0; i<N; i++)
            {
                printf(" %d",W[0][i]);
            }*/
        }
    }
    return 0;
}
