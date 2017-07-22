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

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    scanf(" %d",&n);
    int m;
    scanf(" %d", &m);
    vector<int> v;
    int x;
    for(int i=0; i<n; i++) {
        scanf(" %d",&x);
        v.push_back(x);
    }
    sort(v.begin(), v.end(), cmp);

    if(DEBUG) {
        for(int i=0; i<v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    int res = 0;
    int i = 0;
    while(m > 0) {
        m = m - v[i];
        res++;
        i++;
    }
    printf("%d\n", res);
    return 0;
}
