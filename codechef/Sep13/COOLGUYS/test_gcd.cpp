#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int t = 1000000000;
    int count = 0;
    int i;
    int ans;
    for(i=1;i<=(t+1)/2;i++)
    {
        if(t%i == 0)
        {
            count++;
        }
    }
    cout << count+1 << endl;
    return 0;
}
