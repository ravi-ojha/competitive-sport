#include<stdio.h>
#include<string.h>
int main()
{
    int t,p;
    scanf(" %d",&t);
    for(p=1;p<=t;p++)
    {
        int l,len,i,j,k,count = 0,c=0;
        char mystr[1000011];
        int data[1000011] = {0};
        scanf(" %s",mystr);
        scanf(" %d",&l);
        len = strlen(mystr);
        for(i=0;i<len;i++)
        {
            if(mystr[i] == 'a' || mystr[i] == 'e' || mystr[i] == 'i' || mystr[i] == 'o' || mystr[i] == 'u')
            {
                data[i] = 1;
            }
        }
//        for(i=0;i<len;i++)
//        {
//            printf("%5d",data[i]);
//        }
        for(i=l;i<=len;i++)
        {
            for(j=0;j<=(len-i);j++)
            {
                c = 0;
                for(k=j;k<(j+i);k++)
                {
                    if(data[k] == 0)
                    {
                        c++;
                    }
                    else
                    {
                        c = 0;
                    }
                    if(c == l)
                    {
                        count++;
                        break;
                    }
                }
                //printf("count: %d\n",count);
            }
        }
        printf("Case #%d: %d\n",p,count);
    }
    return 0;
}
