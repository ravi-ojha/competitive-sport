#include <bits/stdc++.h>

// Some constants that are frequently used
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define INF_32 2147483647

// Something to print to console and debug
#define DEBUG true
#define CONSOLE(x) if(DEBUG) {cout << '>' << #x << ':' << x << endl;}

using namespace std;

class Segment {
public:
    int x;
    int y;
};

bool cmp(Segment a, Segment b) {
    if(a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool cmp2(Segment a, Segment b) {
    if(a.x == b.x) {
        return a.y > b.y;
    }
    return a.x > b.x;
}

int main() {
    int n, k;
    scanf(" %d %d", &n, &k);
    vector<Segment> v;
    int x, y;
    for(int i=0; i<n; i++) {
        scanf(" %d %d", &x, &y);
        Segment g;
        g.x = x;
        g.y = y;
        v.push_back(g);
    }

    sort(v.begin(), v.end(), cmp);
    if(DEBUG) {
        for(int i=0; i<n; i++) {
            cout << v[i].x << " " << v[i].y << endl;
        }
        cout << endl;
    }

    return 0;
}
