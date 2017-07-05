#include<stdio.h>
int main()
{
    int T,N,K,M,L,i,j,p,m=0,z=0,y=0,x=0,maxIndex1=0,maxIndex2=0,Oops1=0,Oops2=0,count=0,found=0;
    scanf(" %d",&T);
    while(T--)
    {
        count = 0;
        scanf(" %d %d %d",&N,&K,&M);
        z = 0;
        int a[N],used[N];
        for(i=0; i<N; i++)
        {
            scanf(" %d",&a[i]);
        }

        L = N-K+1;
        p = 0;
        while(p<L)
        {
            int use = 0;
            x = 0;
            y = 0;
            Oops1 = 0;
            Oops2 = 0;
            found = 0;
            maxIndex1 = p;
            maxIndex2 = p;
            for(i=p;i<K+p && i<N;i++)
            {
                if(a[i] > a[maxIndex1])
                {
                    maxIndex1 = i;
                }
            }
            for(i=p;i<K+p && i<N;i++)
            {
                if(a[i]==a[maxIndex1])
                {
                    maxIndex2 = i;
                    found++;
                }
            }
            if(found < M)
            {
                p++;
                printf("\nNot going beyond if found is 0\n");
                continue;
            }

                for(j=maxIndex2;j<maxIndex2+K && j<N;j++)
                {
                    if((a[maxIndex2]+1) == a[j])
                    {
                        Oops2 = 3;
                        break;
                    }
                }
                for(j=maxIndex1-K;j<=maxIndex1 && j>=0;j++)
                {
                    if((a[maxIndex1]+1) == a[j])
                    {
                        Oops1 = 3;
                        break;
                    }
                }
                while(y<z)
                    {
                        if (maxIndex1 == used[y])
                            {use = -1;
                            break;}
                        y++;
                    }
                while(x<z)
                    {
                        if (maxIndex2 == used[x])
                            {use = -2;
                            break;}
                        x++;
                    }
                if (Oops2 == 3 && Oops1 == 3 && use != -2)
                {
                    a[maxIndex2] = a[maxIndex2]+1;
                    used[z] = maxIndex2;
                    z++;
                    count++;
                    p = -1;
                }
                else if(Oops2 == 3 && use != -1)
                {
                    a[maxIndex1] = a[maxIndex1]+1;
                    used[z] = maxIndex1;
                    z++;
                    count++;
                    p = -1;
                }
                else if(Oops1 == 3 && use != -2)
                {
                    a[maxIndex2] = a[maxIndex2]+1;
                    used[z] = maxIndex2;
                    z++;
                    count++;
                    p = -1;
                }


                else if (z == N)
                {
                    printf("%d\n",count);
                    goto end;
                }
                else
                {
                    printf("\nWhy here! ");
                    printf("-1\n");
                    goto end;
                }
                printf("\nArray now:\n");
                for(i=0; i<N; i++)
                {
                    printf(" %d",a[i]);
                }
            p++;
        }

        printf("%d\n",count);
        end:
        ;
    }
return 0;
}
