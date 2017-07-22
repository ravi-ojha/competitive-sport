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
    int n;
    scanf(" %d", &n);
    int m[20010];
    int total = 0;
    for(int i=0; i<n; i++) {
        scanf(" %d", &m[i]);
        total = total + m[i];
    }
    int fair_amount = total/n;
    int res = 0;
    for(int i=0; i<n; i++) {
        if(m[i] < fair_amount) {
            res = res + (fair_amount - m[i]);
        }
    }
    cout << res << endl;
    return 0;
}
