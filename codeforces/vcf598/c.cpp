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

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if(a.first.first == b.first.first) {
        return a.first.second < b.first.second;
    }
    return a.first.first < b.first.first;
}

// double get_slope(int x1, int y1, int x2, int y2) {
//     // x1, y1 is one end and x2, y2 is the other end of the line
//     if((x2 - x1) == 0) {

//     }
//     return (y2 - y1)/(x2 - x1);
// }

// double angle_between_two_lines(double m1, double m2) {
//     // m1 and m2 are slopes of two lines
//     // returns the radian angle between them
//     return PI - abs(atan(m1) - atan(m2));
// }


int main() {
    int n;
    scanf(" %d",&n);
    vector< pair<pair<int, int>, int> > v;
    int x, y;
    for(int i=0; i<n; i++) {
        scanf(" %d %d", &x, &y);
        v.push_back(make_pair(make_pair(x, y), i+1));
    }
    sort(v.begin(), v.end(), cmp);

    double min_theta = 10000000000000;
    int r1, r2;
    double theta;
    for(int i=1; i<v.size()-1; i++) {
        double y1 = v[i].first.first;
        double x1 = -v[i].first.second;
        double y2 = v[i-1].first.first;
        double x2 = -v[i-1].first.second;
        theta = acos((x1*x2 + y1*y2)/(sqrt(x1*x1 + y1*y1)*sqrt(x2*x2 + y2*y2)));

        if(theta > PI) {
            theta = theta - PI;
        }
        if(theta < min_theta) {
            min_theta = theta;
            r1 = v[i].second;
            r2 = v[i-1].second;
        }


        y1 = v[i].first.first;
        x1 = -v[i].first.second;
        y2 = v[i+1].first.first;
        x2 = -v[i+1].first.second;
        theta = acos((x1*x2 + y1*y2)/(sqrt(x1*x1 + y1*y1)*sqrt(x2*x2 + y2*y2)));

        if(theta > PI) {
            theta = theta - PI;
        }
        if(theta < min_theta) {
            min_theta = theta;
            r1 = v[i].second;
            r2 = v[i+1].second;
        }
    }

    printf("%d %d\n", r1, r2);
    return 0;
}
