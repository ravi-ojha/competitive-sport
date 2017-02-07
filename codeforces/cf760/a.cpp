#include <bits/stdc++.h>
#define DEBUG true
using namespace std;

int main() {
    int a[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m, d;
    scanf(" %d %d", &m, &d);
    // int days = a[m];
    // days = days + d - 1;
    // int res = days/7;
    // if(days % 7 != 0) {
    //     res += 1;
    // }
    // printf("%d\n", res);

    d--;
    int count=0,ini=0;
    ini = 7 - d;
    while(ini < a[m]) {
        ini += 7;
        count++;
    }
    printf("%d\n", count+1);
    return 0;
}
