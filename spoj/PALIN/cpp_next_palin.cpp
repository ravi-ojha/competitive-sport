#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline void fastRead_string(char *str)
{
    register char c = 0;
    register int i = 0;

    while (c < 33)
        c = getchar_unlocked();

    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }

    str[i] = '\0';
}
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int i;
        char s[1111111];
        char scopy[1111111];
        char r[1111111];
        //scanf(" %s",s);
        fastRead_string(s);
        int l = strlen(s);
        int c = 0;
        for(i=0;i<l;i++)
        {
            scopy[i] = s[i];
            if(s[i] == '9')
            {
                c++;
            }
        }
        scopy[l] = '\0';
        if(c == l)
        {
            r[0] = '1';
            for(i=1;i<l;i++)
            {
                r[i] = '0';
            }
            r[l] = '1';
            r[l+1] = '\0';
            printf("%s\n",r);
        }
        else
        {
            int mid = strlen(s)/2;
            mid--;
            while(mid>=0 && s[mid] == '9' && s[l-mid-1] == '9')
            {
                mid--;
            }
            int temp = mid;
            while(mid>=0)
            {
                if(s[mid] != s[l-mid-1])
                {
                    break;
                }
                mid--;
            }
            if(mid<0)
            {
                if(l%2 == 1)
                {
                    temp++;
                    if(temp == (l-temp-1))
                    {
                        if(s[temp] == '9')
                        {
                            temp--;
                            s[temp]++;
                            s[l-temp-1]++;
                        }
                        else
                        {
                            s[temp]++;
                        }
                    }
                    else
                    {
                        s[temp]++;
                    }
                }
                else
                {
                    s[temp]++;
                    s[l-temp-1]++;
                }
            }
            else
            {
                while(mid>=0)
                {
                    if(s[mid] == s[l-mid-1])
                    {
                        continue;
                    }
                    else if(s[mid]>s[l-mid-1])
                    {
                        s[l-mid-1] = s[mid];
                    }
                    else
                    {
                        s[mid]++;
                        s[l-mid-1] = s[mid];
                    }
                    mid--;
                }
            }
            printf("%s\n",s);
        }
    }
    return 0;
}
