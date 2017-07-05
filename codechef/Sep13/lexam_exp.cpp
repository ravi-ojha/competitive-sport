#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,i,j,k;
        int p[51],a[51],b[51];
        cin >> n;
        for(i=0;i<n;i++)
        {
            cin >> p[i];
            cin >> a[i];
            cin >> b[i];
        }
        if(n>16)
        {
            cout << "0.0" << endl;
        }
        else
        {
            int upto = 1<<n;
            int shift = 0;
            int prob[17];
            double final = 0;
            for(i=0;i<upto;i++)
            {
                double result = 1.00;
                j = i;
                int c = 0;
                int used[17] = {0};
//                    for(k=1;k<17;k++)
//                    {
//                        printf(" %5d",used[k]);
//                    }
                for(shift = 0; shift<n; shift++)
                {
                    //cout<<"shift "<<shift;
                    if((j>>shift)&1 == 1)
                    //if(!((j>>shift)&1))
                    {
                        //cout<<"takin "<<a[shift];

                        if(used[b[shift]] == 0)
                        {
                            //cout<<"took";
                            used[b[shift]] = 1;
                            c++;
                            prob[b[shift]] = 100 - p[shift];
                        }
                    }
                    else
                    {
                        if(used[a[shift]] == 0)
                        {
                            //cout<<"took";
                            used[a[shift]] = 1;
                            prob[a[shift]] = p[shift];
                            c++;
                        }
                        //cout<<"taking "<<b[shift];

                    }
                }
                //cout << "c"<<c<<endl;
                if(c==n)
                {
                    for(k=1;k<17;k++)
                    {
                        if(used[k] == 1)
                        result = result*((double)prob[k]/100);
                    }
                    final = final + result;
//                    for(k=1;k<17;k++)
//                    {
//                        printf(" %5d",used[k]);
//                    }
//                    cout << endl;
//                    for(k=1;k<17;k++)
//                    {
//                        printf(" %5d",prob[k]);
//                    }
                    //cout << "result " << result<<endl;
                }
            }
            cout << final <<endl;
//            printf("\n\n");
//
//            for(k=1;k<17;k++)
//            {
//                printf(" %5d",prob[k]);
//            }
        }
    }
    return 0;
}
