#include <bits/stdc++.h>

// Some constants that are frequently used
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define INF_32 2147483647

// Something to print to console and debug
#define DEBUG false
#define CONSOLE(x) if(DEBUG) {cout << '>' << #x << ':' << x << endl;}

using namespace std;


int main() {
    vector<long long> sq;
    for(long long i=0; i<1000011; i++) {
        sq.push_back(i*i);
    }

    // for(int i=0; i<10; i++) {
    //     cout << sq[i] << endl;
    // }

    // cout << lower_bound(sq.begin(), sq.end(), 1) - sq.begin() << endl;

    long long a, b;
    scanf(" %lld %lld",&a, &b);
    long long res = 0;

    for(long long i=1; i<=a; i++) {

        long long asq = i*i;

        long long low = asq + 1;
        long long high = asq + b;
        if(DEBUG) {
            CONSOLE(low);
            CONSOLE(high);
        }

        vector<long long>::iterator l, h;

        long long ll;
        long long hh;

        l = lower_bound(sq.begin(), sq.end(), low);

        ll = (l - sq.begin());

        h = upper_bound(sq.begin(), sq.end(), high);

        hh = (h - sq.begin());
        if(DEBUG) {
            CONSOLE(ll);
            CONSOLE(hh);
        }

        res = res + (hh-ll);

    }
    printf("%lld\n", res);

    return 0;
}
