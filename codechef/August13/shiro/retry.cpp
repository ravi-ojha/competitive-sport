#include <iostream>
#include <cstring>
#include <cstdio>

//#define eps 1e-6
using namespace std;

float a[101][10001];
int val[101];
float p[101];
int main()
{
    int t;

    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
                cin >> val[i];
                sum += val[i];
        }
        for(int i = 0; i <= n; i++)
        {
            for(int j = sum; j >= 0; j--)
            {
                a[i][j] = 0.0;
            }
        }
        float ans = 0.0;
        for(int i = 1; i <= n; i++)
        {
                cin >> p[i];
                p[i] /= (float)100.0;
        }
        a[0][0] = 1.0;
        //float ans = 0.0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = sum; j >= 0; j--)
            {
//                if(a[i-1][j] >= eps)
//                {
                    a[i][j+val[i]] += a[i-1][j]*p[i];
                    a[i][j] += a[i-1][j]*(1.0-p[i]);
                    //if(j+val[i] >= sum/2) ans += a[i][j+val[i]];
//                }
            }
        }
       // cout << (sum+1)/2 << endl;
        for(int i = (sum+1)/2; i <= sum; i++)
        {
            ans += a[n][i];
        }
        printf("%f\n", ans);
    }
    return 0;
}
