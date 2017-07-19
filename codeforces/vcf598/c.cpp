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

class Line {
public:
    int x;
    int y;
    long double theta;
    int idx;
};

bool cmp(Line a, Line b) {
    return a.theta < b.theta;
}

// long double get_slope(int x1, int y1, int x2, int y2) {
//     // x1, y1 is one end and x2, y2 is the other end of the line
//     if((x2 - x1) == 0) {

//     }
//     return (y2 - y1)/(x2 - x1);
// }

// long double angle_between_two_lines(long double m1, long double m2) {
//     // m1 and m2 are slopes of two lines
//     // returns the radian angle between them
//     return PI - abs(atan(m1) - atan(m2));
// }


int main() {
    int n;
    scanf(" %d",&n);
    vector< Line > v;
    int x, y;
    for(int i=0; i<n; i++) {
        scanf(" %d %d", &x, &y);

        Line l;
        l.x = x;
        l.y = y;
        l.idx = i+1;
        // We take the line passing through (0,0) (0, 1) as reference i.e line y = 0
        long double theta = acos((-y)/sqrt(x*x + y*y))*(180/PI);

        // theta always comes out to be in between 0 and 180
        // So if x in negative we have to find theta which lies in range 180 - 360.
        if(x < 0) {
            theta = 360 - theta;
        }
        l.theta = theta;
        CONSOLE(theta);
        v.push_back(l);
    }

    sort(v.begin(), v.end(), cmp);
    if(DEBUG) {
        for(int i=0; i<v.size(); i++) {
            cout << v[i].theta << endl;
        }
        cout << "=======" << endl;
    }
    int r1, r2;
    long double min_theta = 1000000000;
    for(int i=1; i<v.size(); i++) {
        int i1;
        int i2;

        i1 = i;

        i2 = i-1;

        long double diff = fabs(v[i1].theta - v[i2].theta);
        if(diff > 180) {
            diff = 360 - diff;
        }
        if(DEBUG) {cout << diff << " " << v[i1].x << ", " << v[i1].y << " " << v[i2].x << ", " << v[i2].y << "==" << v[i1].idx << "-" << v[i2].idx << endl;}
        if(diff < min_theta) {
            min_theta = diff;
            r1 = v[i1].idx;
            r2 = v[i2].idx;
        }
        CONSOLE(min_theta);
        CONSOLE(r1);
        CONSOLE(r2);
    }
    int i1, i2;
    i1 = v.size()-1;
    i2 = 0;
    long double diff = fabs(v[i1].theta - v[i2].theta);
    if(diff > 180) {
        diff = 360 - diff;
    }
    if(DEBUG) {cout << diff << " " << v[i1].x << ", " << v[i1].y << " " << v[i2].x << ", " << v[i2].y << "==" << v[i1].idx << "-" << v[i2].idx << endl;}
    if(diff < min_theta) {
        min_theta = diff;
        r1 = v[i1].idx;
        r2 = v[i2].idx;
    }
    CONSOLE(min_theta);
    CONSOLE(r1);
    CONSOLE(r2);
    printf("%d %d\n", r1, r2);

    return 0;
}
