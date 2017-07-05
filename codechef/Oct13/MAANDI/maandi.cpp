#include<cstdio>
//#include<cstdlib>
#include<sstream>
#include<string>
using namespace std;
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n;
        scanf(" %d",&n);
        int i = 2;
        int res = 0;
        string four = "4";
        string seven = "7";

        stringstream nn;
        nn << n;
        string nnn = nn.str();

        if((nnn.find(four) != string::npos) || (nnn.find(seven) != string::npos))
        {
            //printf("hopy %d\n",nnn.find(four) != string::npos);
            res++;
        }

        while(i*i <= n)
        {
            if(n%i == 0)
            {
                int j = n/i;
                stringstream ii,jj;
                ii << i;
                jj << j;
                string iii = ii.str();
                string jjj = jj.str();

                if((iii.find(four) != string::npos) || (iii.find(seven) != string::npos))
                {
                    res++;
                }
                if(j!=i)
                {
                    if((jjj.find(four) != string::npos) || (jjj.find(seven) != string::npos))
                    {
                        res++;
                    }
                }
            }
            i++;
        }
        printf("%d\n",res);
    }
    return 0;
}
