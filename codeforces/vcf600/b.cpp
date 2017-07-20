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

int my_search(vector<int> v, int vlen, int to_search) {
    // returns the idx of the number that is just greater than to_search
    int left = 0;
    int right = vlen;

    while(left < right) {
        int mid = (left + right)/2;
        if(v[mid] <= to_search) {
            left = mid+1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int n, m, x;
    scanf(" %d %d", &n, &m);
    vector<int> a;
    vector<int> b;
    for(int i=0; i<n; i++) {
        scanf(" %d", &x);
        a.push_back(x);
    }
    for(int i=0; i<m; i++) {
        scanf(" %d", &x);
        b.push_back(x);
    }

    sort(a.begin(), a.end());

    vector<int>::iterator up;
    for(int i=0; i<m; i++) {
        up = upper_bound(a.begin(), a.end(), b[i]);
        cout << up - a.begin() << " ";
        //cout << my_search(a, a.size(), b[i]) << " ";
    }
    cout << endl;

    return 0;
}
