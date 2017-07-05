#include<stdio.h>


int findOnes(int i)
{
      int count = 0;
      int j=1,m=1,k=0;
      while (i >= j)       // value of j is extended upto the 8,16,32,64 etc acc. to requirement
      {
            j = j << 1;
            m++;
      }
      while(k<m)
      {
              if ((j&i)>0)
                       count++;
              j = j >> 1;
              k++;
      }
      return count;
}
int binToDec(char * s)
{
    int i,j=0,ans,res=0;
    for(i=strlen(s)-1;i>=0;i--)
    {
        ans = 1;
        if(s[i] == 49)
        {
            //printf("\nIts 1..");
            ans = ans<<j;
            res = res+ans;
        }
        //printf("\nDecimal: %d",res);
        //printf("\ns[%d]=%d",i,s[i]);
        j++;
    }
    return res;
    //printf("\nNumber in Decimal: %d",res);
}

main()
{
    int T,n,a,b,i,aNum,bNum,sum;
    scanf(" %d",&T);
    while(T--)
    {
        int result;
        char ansStr[32] = {0};
        scanf(" %d %d %d",&n,&a,&b);
        aNum = findOnes(a);
        bNum = findOnes(b);
        sum = aNum+bNum;
        if(sum == n)
        {
            for(i=0;i<n;i++)
            {
                ansStr[i] = '1';
            }
            result = binToDec(ansStr);
            printf("%d\n",result);
        }
        else if(sum < n)
        {
            for(i=0;i<sum;i++)
            {
                ansStr[i] = '1';
            }
            while(i<n)
            {
                ansStr[i] = '0';
                i++;
            }
            result = binToDec(ansStr);
            printf("%d\n",result);
        }
        else
        {
            sum = 2*n - sum;
            for(i=0;i<sum;i++)
            {
                ansStr[i] = '1';
            }
            while(i<n)
            {
                ansStr[i] = '0';
                i++;
            }
            result = binToDec(ansStr);
            printf("%d\n",result);
        }
        //printf("aNum = %d   bNum = %d",aNum,bNum);
    }
    return 0;
}
