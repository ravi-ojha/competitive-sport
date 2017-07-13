#include <bits/stdc++.h>

// Some constants that are frequently used
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

// Something to print to console and debug
#define DEBUG false
#define CONSOLE(x) if(DEBUG) {cout << '>' << #x << ':' << x << endl;}

using namespace std;
long long dp[2020][1010];
int main() {
    int n, k;
    long long p;

    cin >> n >> k >> p;

    long long a[1010];
    long long b[2020];

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    for(int i=0; i<k; i++) {
        cin >> b[i];
    }



    for(int i=0; i<k; i++) {
        for(int j=0; j<n; j++) {
            dp[i][j] = abs(b[i] - a[j]) + abs(b[i] - p);
        }
    }


    vector<long long> res;
    for(int i=0; i<n; i++) {
        long long mn = 1000000000000000;
        for(int j=0; j<k; j++) {
            mn = min(mn, dp[j][i]);
        }
        res.push_back(mn);
    }

    long long ans = -1;
    int res_len = res.size();
    for(int i=0; i<res_len; i++) {
        ans = max(ans, res[i]);
    }

    cout << ans;

    return 0;
}
