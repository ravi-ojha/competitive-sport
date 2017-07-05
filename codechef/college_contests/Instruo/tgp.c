#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000001];
    gets(a);
    int l,i;
    l = strlen(a);
    int b[26] = {0};
    for(i=0;i<l;i++)
    {
        b[a[i]-97]++;
    }
    int count = 0;
    if(l&1)
    {
//        printf("Ram\n");
            puts("Ram");
    }
    else
    {
        for(i=0;i<26;i++)
        {
            if(b[i]&1)
            {
                count++;
            }
        }
        //count = 26-count;
        if(count == 0)
        {
            //printf("Ram\n");
            puts("Ram");
        }
        else if(count == 2)
        {
            //printf("Shyam\n");
            puts("Shyam");
        }
        else
        {
            //printf("Shyam\n");
            puts("Shyam");
        }
    }
//    else
//    {
////        for(i=0;i<26;i++)
////        {
////            if(b[i]%2 == 0)
////            {
////                count++;
////            }
////        }
////        count = 26-count;
////        if(count == 1)
////        {
////            printf("Ram\n");
////        }
////        else if(count%2 == 1)
////        {
////            printf("Ram\n");
////        }
//        printf("Ram\n");
//    }
    return 0;
}
