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
    int n, x;
    scanf(" %d %d", &n, &x);

    vector< pair <long long, pair<int, int> > > cost_by_diff[200010];

    // Initialize with max
    for(int i=0; i< 200010; i++) {
        cost_by_diff[i] = INF_32;
    }

    int l, r, diff;
    long long c;
    for(int i=0; i<n; i++) {
        scanf(" %d %d %lld", &l, &r, &c);
        diff = r - l + 1;
        cost_by_diff[diff].push_back(make_pair(c, make_pair(l, r)));
    }

    // Sort each ith vector in cost_by_diff
    for(int i=1; i<200010; i++) {
        sort(cost_by_diff[i].begin(), cost_by_diff[i].end());
    }

    for(int i=1; i<200010; i++) {
        if(i < x) {
            int j = x-i;
            for(int k=0; k<cost_by_diff[j].size(); k++) {
                if()
            }
        }
    }

    return 0;
}
