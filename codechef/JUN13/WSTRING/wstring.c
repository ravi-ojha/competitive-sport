#include<stdio.h>

int read()
{
    int _n = 0;
    char p = getchar_unlocked();
    for(;p<33;) { p = getchar_unlocked(); }
    while(p>32)
    {
        _n = (_n<<3) + (_n<<1) + (p-'0');
        p = getchar_unlocked();
    }
    return _n;
}

int max(int a[])
{
    int m = 0,i;
    for(i=97;i<123;i++)
    {
        if(a[i]>m)
        {
            m = a[i];
        }
    }
    return m;
}
int main()
{
    char ch;
    int t;
    //scanf(" %d",&t);
    t = read();
    //ch = getchar();
    while(t--)
    {
        int p;
        int goku[11111] = {0};
        int naruto[11111] = {0};
        int gohan[11111] = {0};
        int length;
        //int hashIndex[11111];
        char s[11111];
        int freq1[125] = {0};
        int freq2[125] = {0};
        scanf(" %s",s);
        //gets(s);
        //length = strlen(s);
        int chichi = 1;
        int i = 0;
        while(s[i]!='\0')
        {
            if(s[i] == '#')
            {
                //hashIndex[chichi] = i;
                goku[chichi] = max(freq1);
                gohan[chichi] = max(freq2);
                for(p=97;p<123;p++)
                {
                    freq2[p] = 0;
                }
                chichi++;
            }
            else
            {
                freq1[s[i]]++;
                freq2[s[i]]++;
            }
            i++;
        }
        gohan[chichi] = max(freq2);
        chichi++;
        int hinata = 1;
        i=0;
        while(s[i]!='\0')
        {
            if(s[i] == '#')
            {
                naruto[hinata] = max(freq1);
                hinata++;
            }
            else
            {
                freq1[s[i]]--;
            }
            i++;
        }
//        for(i=0;i<11;i++)
//        {
//            printf("%4d",i);
//        }
//        printf("\n");
//        for(i=0;i<11;i++)
//        {
//            printf("%4d",hashIndex[i]);
//        }
//        printf("\n");
//        for(i=0;i<11;i++)
//        {
//            printf("%4d",gohan[i]);
//        }
//        printf("\n");
//        for(i=0;i<11;i++)
//        {
//            printf("%4d",goku[i]);
//        }
//        printf("\n");
//        for(i=0;i<11;i++)
//        {
//            printf("%4d",naruto[i]);
//        }
//        printf("\n");

        int res = 0, final = 0;
        for(i=1;i<(chichi-3);i++)
        {
            //printf(" %d %d %d %d\n", goku[i],gohan[i+1],gohan[i+2],naruto[i+2]);
            if(goku[i] != 0 && gohan[i+1] != 0 && gohan[i+2] != 0 && naruto[i+2] != 0)
            {
                res = goku[i] + gohan[i+1] + gohan[i+2] + naruto[i+2];
                //printf(" %d %d %d %d\n", goku[i],gohan[i+1],gohan[i+2],naruto[i+2]);
                //printf(" %d\n",res);
            }
            if(res > final)
            {
                final = res;
            }
        }
        if(final == 0)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n",final+3);
        }
    }
    return 0;
}
