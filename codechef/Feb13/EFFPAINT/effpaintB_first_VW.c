#include<stdio.h>
int main()
{
    char a[51][51];
    int N,i,j,xBEG,xEND,count=0;
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
            if(a[i][j] == 'W')
            {
                xBEG = i;
                while(a[i][j] == 'W' && i<N)
                {
                    i++;
                }
                xEND = i-1;
//                printf("\n%d %d %d %d B",xBEG,j,xEND,j);
                count++;
            }
        }
    }
    printf("%d\n",count+1);
    printf("0 0 %d %d B\n",N-1,N-1);
    for(j=0;j<N;j++)
    {
        for(i=0;i<N;i++)
        {
            if(a[i][j] == 'W')
            {
                xBEG = i;
                while(a[i][j] == 'W' && i<N)
                {
                    i++;
                }
                xEND = i-1;
                printf("%d %d %d %d W\n",xBEG,j,xEND,j);
                //count++;
            }
        }
    }
    return 0;
}
