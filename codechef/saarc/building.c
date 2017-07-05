#include<stdio.h>
#include<string.h>
int main()
{
    int T,p;
    scanf(" %d",&T);
    for(p=1;p<=T;p++)
    {
        int count = 0;
            int y=0;
        int n,i,j,k,g,w,v,x,flag =0,r;
        char str1[101][1002],str2[101][1002],bcode[1001];
        int a[101] = {0};
//        for(g=0;g<102;g++)
//        printf(" %d",a[g]);
        scanf(" %d",&n);
        for(k=0;k<n;k++)
        {
            scanf(" %[^\n]",str1[k]);
            j=0;
            for(i=0;str1[k][i] != '\0';i++)
            {
                if(str1[k][i] >= 65 && str1[k][i] <= 90)
                {
                    str2[k][j] = str1[k][i];
                    j++;
                }
                else if(str1[k][i] >= 97 && str1[k][i] <= 122)
                {
                    str2[k][j] = str1[k][i] - 32;
                    j++;
                }
            }
            str2[k][j] = '\0';

            //j--;
        }
//        for(i=0;i<n;i++)
//        {
//            printf(" %s\n",str1[i]);
//            printf(" %s\n",str2[i]);
//        }
        scanf(" %s",bcode);
        for(w=0;w<n;w++)
        {
            y = 0;
            count = 0;
            for(v=0;v<strlen(bcode);v++)
            {
                for(x=y;x<strlen(str2[w]);x++)
                {
                    if(bcode[v] == str2[w][x])
                    {
                        //printf("check");
                        //flag = 1;
                        y = x+1;
                        v++;
                        count++;
                        //printf("x = %d\n",y);
                        continue;
                    }
                }
//                        break;
//                    }
//                    else
//                    {
//                    flag = 0;}
////                }
//                if(flag == 0)
//                break;
//                else
//                {count++;
//                continue;}
            }
            if(count == strlen(bcode))
            {
                a[w] = 1;
            }
        }
        printf("Data Set %d:\n",p);
        for(r=0;r<n;r++)
        {
            if(a[r] == 1)
            printf("%s\n",str1[r]);
        }
    }
    return 0;
}
