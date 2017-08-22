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

bool cmp(int i, int j) {
    return i>j;
}

bool cmp2(pair<int, int> i, pair<int, int> j) {
    return i.first < j.first;
}

int main() {
    int n;
    scanf(" %d", &n);
    vector<int> a;
    vector<int> b;
    vector< pair<int, int> > bc;
    int x, y;
    for(int i=0; i<n; i++) {
        scanf(" %d",&x);
        a.push_back(x);
    }
    for(int i=0; i<n; i++) {
        scanf(" %d",&y);
        b.push_back(y);
        bc.push_back(make_pair(y, i));
    }

    sort(a.begin(), a.end(), cmp);
    sort(bc.begin(), bc.end(), cmp2);

    int res[1000111] = {0};
    for(int i=0; i<bc.size(); i++) {
        res[bc[i].second] = a[i];
    }

    for(int i=0; i<1000111; i++) {
        if(res[i] != 0) {
            printf("%d ", res[i]);
        }
    }
    printf("\n");

    return 0;
}
