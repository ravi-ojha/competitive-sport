
#include<stdio.h>
int main()
{
    int i,j,k,m,n,temp,low,high,stepCount=0;
    int T, N,M;
    int W[100];
    int count = 0;
    scanf(" %d",&T);
    while(T--)
    {
        scanf(" %d",&N);
        for(i=0; i<N; i++)
        {
            scanf(" %d",&W[i]);
        }
        /*printf("Just to confirm: ");
        for(i=0; i<N; i++)
        {
            printf(" %d",W[i]);
        }
        printf("\n");*/
        M = N;
        for(k=0;k<N;k++)
        {
            for(j=0;j<M-1;j++)
            {

                if(W[j] > W[j+1])
                {

                    temp = W[j];
                    W[j] = W[j+1];
                    W[j+1] = temp;
                }
            }
            //display(a);
            M--;
        }

        /*printf("\nSorted: Just to confirm\n");
        for(i=0; i<N; i++)
        {
            printf(" %d",W[i]);
        }*/

        stepCount = 0;

        while(1)
        {
            //count = 0;

            if (W[0] == W[N-1])
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
            j = N-1;
            while(1)
            {
                if(W[j] == W[j-1])
                    {
                        j--;
                    }
                else
                    break;
            }
            //printf("\nValue of n: %d",j);

            for(i=0; i<N; i++)
            {
                if(i == j)
                {
                    continue;
                }
                W[i] = W[i] + 1;
            }
            stepCount++;
            /*printf("\nAgain Just to confirm\n");
            for(i=0; i<N; i++)
            {
                printf(" %d",W[i]);
            }
            count++;*/
        }
    }
    return 0;
}
