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

// Comparator for reverse sorting
bool cmp(int a, int b)
{
    return a > b;
}

int main() {
    int n;
    scanf(" %d",&n);
    vector<int> v;
    int res = 0;
    int to_remove = 1;
    int so_far = 1;
    for(int i=0; i<2*n; i++) {
        string s;
        cin >> s;
        int x;
        if(s[0] == 'a') {
            scanf(" %d",&x);
            so_far = max(so_far, x);
            v.push_back(x);
        } else {
            if(v.back() == to_remove) {
                v.pop_back();
                to_remove++;
            } else {
                res++;

                for(int j=to_remove; j<=so_far; j++) {
                    v[j] = to_remove + so_far - j;
                }
                v.pop_back();
                to_remove++;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
