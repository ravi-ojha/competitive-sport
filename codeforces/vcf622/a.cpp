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
    vector<long long> v;
    for(long long i=1; i<15000000; i++) {
        v.push_back((i*(i+1))/2);
    }
    long long n;
    scanf(" %I64d", &n);
    vector<long long>::iterator it;
    it = lower_bound(v.begin(), v.end(), n);
    int idx = it - v.begin();
    if(v[idx] == n) {
        printf("%d\n", idx+1);
    } else {
        printf("%I64d\n", n-v[idx-1]);
    }
    return 0;
}
