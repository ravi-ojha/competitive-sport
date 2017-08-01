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
    int a[1000111];
    for(int i=1; i<=n; i++) {
        scanf(" %d",&a[i]);
    }
    map<int, int> mp;
    vector< pair<int, int> > res;
    map<int, int>::iterator it;

    int idx_done = 1;
    for(int i=1; i<=n; i++) {
        it = mp.find(a[i]);
        if(it != mp.end()) {
            res.push_back(make_pair(idx_done, i));
            idx_done = i+1;
            mp.clear();
        } else {
            mp[a[i]] = i;
        }
    }

    if(res.size() != 0 && mp.size() != 0) {
        pair<int, int> s = res.back();
        res.pop_back();
        s.second = n;
        res.push_back(s);
    }
    if(res.size() != 0) {
        printf("%d\n", res.size());
        for(int i=0; i<res.size(); i++) {
            printf("%d %d\n", res[i].first, res[i].second);
        }
    } else {
        printf("-1\n");
    }
    return 0;
}
