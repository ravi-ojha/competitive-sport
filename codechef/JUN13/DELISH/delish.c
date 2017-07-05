#include<stdio.h>

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        long long toPrint;
        int n,i;
        scanf(" %d",&n);
        long long d[n+10];
        long long goku[n+10];
        long long edward[n+10];
        long long alphonse[n+10];
        scanf(" %lld",&d[1]);
        goku[1] = d[1];
        int minIndex,maxIndex;
        long long minValue = 10000000000, maxValue = -10000000000;
        if(goku[1]<minValue)
        {
            minValue = goku[1];
            minIndex = 1;
        }
        if(goku[1]>maxValue)
        {
            maxValue = goku[1];
            maxIndex = 1;
        }
        for(i=2;i<=n;i++)
        {
            scanf(" %lld",&d[i]);
            goku[i] = goku[i-1] + d[i];
            if(goku[i]<minValue)
            {
                minValue = goku[i];
                minIndex = i;
            }
            if(goku[i]>maxValue)
            {
                maxValue = goku[i];
                maxIndex = i;
            }
        }
        long long finalMin = 1000000000000000, finalMax = -1000000000000000;
        if(minIndex < maxIndex)
        {
            edward[1] = minValue;
            if(finalMin>edward[1])
            {
                finalMin = edward[1];
            }
            for(i=1;i<minIndex;i++)
            {
                edward[i+1] = minValue - goku[i];
                if(finalMin>edward[i+1])
                {
                    finalMin = edward[i+1];
                }
            }
            //alphonse[1] = maxValue;
            int coun = 1;
//            if(finalMax < alphonse[1])
//            {
//                finalMax = alphonse[1];
//            }
            for(i=minIndex;i<maxIndex;i++)
            {
                alphonse[coun] = maxValue - goku[i];
                if(finalMax < alphonse[coun])
                {
                    finalMax = alphonse[coun];
                }
                coun++;
            }
            toPrint = finalMax - finalMin;
        }
        else
        {
            edward[1] = maxValue;
            if(finalMax < edward[1])
            {
                finalMax = edward[1];
            }
            for(i=1;i<maxIndex;i++)
            {
                edward[i+1] = maxValue - goku[i];
                if(finalMax < edward[i+1])
                {
                    finalMax = edward[i+1];
                }
            }
            //alphonse[1] = minValue;
            int coun = 1;
//            if(finalMin > alphonse[1])
//            {
//                finalMin = alphonse[1];
//            }
            for(i=maxIndex;i<minIndex;i++)
            {
                alphonse[coun] = minValue - goku[i];
                if(finalMin > alphonse[coun])
                {
                    finalMin = alphonse[coun];
                }
                coun++;
            }
            toPrint = finalMax - finalMin;
        }
        printf("%lld\n",toPrint);
//        for(i=1;i<=n;i++)
//        {
//            printf(" %4lld",goku[i]);
//        }
//        printf("\n");
//        printf(" maxIndex = %d   maxValue = %lld\n",maxIndex,maxValue);
//        printf(" minIndex = %d   minValue = %lld\n",minIndex,minValue);

    }
    return 0;
}
