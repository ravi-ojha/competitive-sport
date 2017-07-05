#include<stdio.h>
#include<string.h>
main()
{
    int T;
    scanf(" %d",&T);
    while(T--)
    {
        int i,j,l,flag = 0;
        char mstring[25];
        scanf(" %s",mstring);
        l = strlen(mstring);
        j = l-1;
        for(i=0;i<l/2;i++,j--)
        {
            if(mstring[i] != mstring[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}
