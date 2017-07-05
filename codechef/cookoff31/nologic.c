#include<stdio.h>

int main()
{
    int T;
    scanf(" %d",&T);
    while(T--)
    {
        int i,j=0,k,flag=0,iflag=0;
        char str1[320],str2[320] = {0};
        scanf(" %[^\n]",str1);
        for(i=0;str1[i] != '\0';i++)
        {
            if(str1[i] >= 65 && str1[i] <= 90)
            {str2[j] = str1[i] + 32;
            j++;}
            else if(str1[i] >= 97 && str1[i] <= 122)
            {str2[j] = str1[i];
            j++;}
            else
            {str2[j] = str1[i];
            j++;}
        }
        //j--;
        //puts(str1);
        //printf(" %s\n",str2);
        for(i=97;i<123;i++)
        {
            for(k=0;k<j;k++)
            {
                //printf("%c %c\n",i,str2[k]);
                if(i == (int)(str2[k]))
                {flag = 1;
                break;}
                else
                flag = 0;
            }
            if(flag == 1)
            {
                continue;
            }
            else
            {
                iflag = 1;
                goto here;
            }
        }
        here:
        if(iflag == 1)
        {
            printf("%c\n",i);
        }
        else
        {
            printf("~\n");
        }
    }
    return 0;
}
