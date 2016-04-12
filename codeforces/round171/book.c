#include<stdio.h>

int main()
{
    int n,t,i,j,k,p,low,high,flag=0,count = 0,max=0,min=10000;
    long long sum=0,maxsum=0;
    scanf(" %d %d",&n,&t);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf(" %d",&a[i]);
        if(a[i]<min)
        min = a[i];
    }
    for(j=n;j>0;j--)
    {
//        printf("j=%d\n",j);
        //sum = 0;
        if(j==1)
        {
            if(min<=t)
            {printf("1\n");
            goto hell;}
            else
            {printf("0\n");
            goto hell;}
        }
        for(k=0;k<(n-j+1);k++)
        {
            sum = 0;
            for(i=k;i<(k+j);i++)
            {
                sum = sum + a[i];
            }
//            printf("sum = %d\t",sum);
//            printf("j = %d\n",j);
            if(sum<=t)
            {
                flag = 1;
                goto here;
            }
        }
    }
    here:
    if(flag == 1)
    {
        printf("%d\n",j);
    }
    else
    {
        printf("0\n");
    }
//    low = 0;
//    high = n-1;
//    quicksort(a,low,high);
//for(j=0;j<(n-1);j++)
//    {
//        sum = 0;
//        count = 0;
//        for(i=j;i<n&&sum<=t;i++)
//        {
//            sum = sum + a[i];
//            count++;
//        }
//        if(sum>t)
//        {sum = sum-a[i-1];
//        count = count - 1;}
//        if(count > max)
//        {
//            printf("sum = %d\n",sum);
//            max = count;
//            maxsum = sum;
//        }
//    }
//    printf("maxsum = %d\n");
//    if(maxsum>t)
//    {
//        max = max - 1;
//        printf("oh here\n");
//    //sum = sum - a[i-1];
//    }
//    printf("%d\n",max);
    hell:
    return 0;
}
