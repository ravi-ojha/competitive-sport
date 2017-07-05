#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int i;
        char help[30], cypher[150011], cc[150011], res[150011];
        int freq[30] = {0};
        scanf(" %s",help);
        scanf(" %[^\n]",cypher);
        int clen = strlen(cypher);
        for(i=0;i<clen;i++)
        {
            if(cypher[i] >= 'A' && cypher[i] <= 'Z')
            {
                cc[i] = cypher[i] + 32;
            }
            else
            {
                cc[i] = cypher[i];
            }
        }
        cc[i] = '\0';
        printf(" cc = %s\n",cc);
        //printf(" %s %d",cypher,strlen(cypher));
        for(i=0;i<clen;i++)
        {
            printf("%c\n",cc[i]);
            int z = cc[i] - 'a';
            printf("z = %d\n",z);
            if(z < 26 && z>= 0)
            {
                freq[z]++;
                res[i] = '*';
            }
            else
            {
                res[i] = cc[i];
            }
        }
        res[clen] = '\0';
        printf(" %s\n",res);

        for(i=0;i<26;i++)
        {
            printf(" %c",i+'a');
        }
        printf("\n");
        for(i=0;i<26;i++)
        {
            printf(" %d",freq[i]);
        }
        printf("\n");
    }
    return 0;
}
