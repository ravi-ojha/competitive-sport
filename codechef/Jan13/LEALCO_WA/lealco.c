#include<stdio.h>
int main()
{
    int T,N,K,M;
    int p,i,j,k;
    int count,maxIndex1,maxIndex2,found,Oops,Oops1,Oops2,kay,minus;
    scanf(" %d",&T);
    while(T--)
    {
        count = 0;
        scanf(" %d %d %d",&N,&K,&M);
        int a[N];
        int used[N];
        for(i=0; i<N; i++)
        {
            scanf(" %d",&a[i]);
            used[i] = 0;
        }
        if(M==1)
        {
            printf("-1");
            goto end;
        }
        int L = N-K+1;
        for(p=0;p<L;p++)
        {
            minus = 0;
            kay = 0;
            Oops = 0;
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
            //printf("\nmaxIndex1 = %d and maxIndex2 = %d",maxIndex1,maxIndex2);
            if(found<M)
            {
                //printf("\ncontinuing..");
                continue;
            }
            if((maxIndex1-K+1)>=0)
                j = maxIndex1-K+1;
            else
                j = 0;
            while(j>=0 && j<maxIndex1)
            {
                if((a[maxIndex1]+1) == a[j])
                {
                    Oops1 = 1; //if Oops1 becomes 1 then I should not incre a[maxIndex1]
                    Oops = 1;
                    //printf("\nOops became %d",Oops);
                    break;
                }
                j++;
            }
            for(j=maxIndex2+1;j<N && j<maxIndex2+K-1;j++)
            {
                if((a[maxIndex2]+1) == a[j])
                {
                    Oops2 = 1; //if Oops2 becomes 1 then I should not incre a[maxIndex2]
                    Oops = 2;
                    //printf("\nOops became %d",Oops);
                    break;
                }
            }
            if(Oops1 == 1 && Oops2 == 1)
            {
                Oops = 3;
            }
            if(Oops1 == 0 && Oops2 == 0)
            {
                if(found == K)
                {
                    //printf("\nWent to middle..");
                    for(k=maxIndex2;k<maxIndex2+K;k++)
                    {
                        if(a[k] == a[maxIndex2])
                        {
                            kay++;
                        }
                    }
                    if(kay==M)
                        Oops = 1;
                    else
                        maxIndex1 = (maxIndex1+maxIndex2)/2;
                }
                else
                    Oops = 5;
            }
            switch(Oops)
            {
                case 1:
                if (used[maxIndex2] == 0)
                    {a[maxIndex2] += 1;
                    used[maxIndex2] = 1;
                    count++;}
                else if (used[maxIndex1] == 0)
                    {
                        a[maxIndex1] += 1;
                        used[maxIndex1] = 1;
                        count++;
                    }
                    p = -1;
                break;

                case 2:
                case 3:
                case 4:
                case 5:
                if (used[maxIndex1] == 0)
                    {a[maxIndex1] += 1;
                    used[maxIndex1] = 1;
                    count++;}
                else if (used[maxIndex2] == 0)
                    {
                        a[maxIndex2] += 1;
                        used[maxIndex2] = 1;
                        count++;
                    }
                    p = -1;
                break;
            }
            for(i=0;i<N;i++)
            {
                if(used[i] == 1)
                    minus++;
            }
            if(minus == N)
            {
                printf("-1");
                goto end;
            }
            /*printf("\nArray now:\n");
            for(i=0; i<N; i++)
            {
                printf(" %d",a[i]);
            }*/
        }
        printf("%d\n",count);
        end:
        ;
    }
    return 0;
}
