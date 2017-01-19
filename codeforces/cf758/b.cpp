#include <bits/stdc++.h>
#define DEBUG true
using namespace std;


int main() {
    int n;
    scanf(" %d", &n);
    int a[110];
    for(int i=0;i<n;i++) {
        scanf(" %d",&a[i]);
    }
    int maxi = a[0];
    for(int i=0;i<n;i++) {
        maxi = max(maxi, a[i]);
    }
    int result = 0;
    for(int i=0;i<n;i++) {
        result += (maxi - a[i]);
    }
    printf("%d\n", result);
    return 0;
}
