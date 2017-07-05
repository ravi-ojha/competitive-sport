#include<stdio.h>
int main()
{
    char a[51][51];
    int N,i,j,xBEG,xEND,countB=0,countW=0;
    scanf(" %d",&N);
    for(i=0;i<N;i++)
    {
//        for(j=0;j<N;j++)
//        {
//            scanf(" %c",&a[i][j]);
//        }
        scanf(" %s",a[i]);
    }
    for(j=0;j<N;j++)
    {
        for(i=0;i<N;i++)
        {
            if(a[j][i] == 'B')
            {
                xBEG = i;
                while(a[j][i] == 'B' && i<N)
                {
                    i++;
                }
                xEND = i-1;
//                printf("\n%d %d %d %d B",xBEG,j,xEND,j);
                countB++;
            }
        }
    }
    for(j=0;j<N;j++)
    {
        for(i=0;i<N;i++)
        {
            if(a[j][i] == 'W')
            {
                xBEG = i;
                while(a[j][i] == 'W' && i<N)
                {
                    i++;
                }
                xEND = i-1;
//                printf("\n%d %d %d %d B",xBEG,j,xEND,j);
                countW++;
            }
        }
    }
    countW++;
    if(countB>countW)
    {
        printf("%d\n",countW);
        printf("0 0 %d %d B\n",N-1,N-1);
        for(j=0;j<N;j++)
        {
            for(i=0;i<N;i++)
            {
                if(a[j][i] == 'W')
                {
                    xBEG = i;
                    while(a[j][i] == 'W' && i<N)
                    {
                        i++;
                    }
                    xEND = i-1;
                    printf("%d %d %d %d W\n",j,xBEG,j,xEND);
                    //count++;
                }
            }
        }
    }
    else
    {
        printf("%d\n",countB);
        for(j=0;j<N;j++)
        {
            for(i=0;i<N;i++)
            {
                if(a[j][i] == 'B')
                {
                    xBEG = i;
                    while(a[j][i] == 'B' && i<N)
                    {
                        i++;
                    }
                    xEND = i-1;
                    printf("%d %d %d %d B\n",j,xBEG,j,xEND);
                    //count++;
                }
            }
        }
    }
    return 0;
}
