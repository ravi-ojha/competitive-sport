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

class data {
public:
    int x;
    int y;
    int s;
};

data z[1010][1010];

int n, m;
char g[1010][1010];
int v[1010][1010];
int res[1010][1010];
int cnt = 0;
void dfs(int x, int y) {
    if(x < 0 || y <0 || x >= n || y >= m) {
        return;
    }
    // If this cell is not passable then return
    if(g[x][y] == '*') {
        return;
    }
    // If this cell was visited then return
    if(v[x][y] == 1) {
        return;
    }
    v[x][y] = 1;
    if(x-1 >= 0 && v[x-1][y] != 1 && g[x-1][y] == '.') {
        cnt++;
        dfs(x-1, y);
    }
    if(x+1 < n && v[x+1][y] != 1 && g[x+1][y] == '.') {
        cnt++;
        dfs(x+1, y);
    }
    if(y-1 >= 0 && v[x][y-1] != 1 && g[x][y-1] == '.') {
        cnt++;
        dfs(x, y-1);
    }
    if(y+1 < m && v[x][y+1] != 1 && g[x][y+1] == '.') {
        cnt++;
        dfs(x, y+1);
    }
    return;
}


void update_res(int x, int y, int cnt, int x1, int y1) {
    if(x < 0 || y <0 || x >= n || y >= m) {
        return;
    }
    // If this cell is not passable then return
    if(g[x][y] == '*') {
        return;
    }
    // If this cell was visited then return
    if(res[x][y] != -1) {
        return;
    }
    res[x][y] = cnt;
    z[x+1][y+1].x = x1;
    z[x+1][y+1].y = y1;
    z[x+1][y+1].s = cnt;
    update_res(x-1, y, cnt, x1, y1);
    update_res(x+1, y, cnt, x1, y1);
    update_res(x, y-1, cnt, x1, y1);
    update_res(x, y+1, cnt, x1, y1);
    return;
}

int if_in_v(vector<data> v, data d) {
    int res = 0;
    for(int i=0; i<v.size(); i++) {
        if(v[i].x == d.x && v[i].y == d.y && v[i].s == d.s) {
            res = 1;
            break;
        }
    }
    return res;
}

int main() {

    scanf(" %d %d", &n, &m);
    for(int i=0; i<1010; i++) {
        for(int j=0; j<1010; j++) {
            v[i][j] = 0;
            res[i][j] = -1;
        }
    }

    for(int i=0; i<1010; i++) {
        for(int j=0; j<1010; j++) {
            z[i][j].x = 0;
            z[i][j].y = 0;
            z[i][j].s = 0;
        }
    }

    for(int i=0; i<n; i++) {
        scanf(" %s", g[i]);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(g[i][j] == '.' && res[i][j] == -1) {
                cnt = 1;
                dfs(i, j);
                update_res(i, j, cnt, i, j);
            }
        }
    }

    if(DEBUG) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                printf("%d", res[i][j]);
            }
            printf("\n");
        }
    }


    int ans[1010][1010];
    int final[1010][1010];
    for(int i=0; i<1010; i++) {
        for(int j=0; j<1010; j++) {
            ans[i][j] = -1;
            final[i][j] = 0;
        }
    }



    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ans[i+1][j+1] = res[i][j];
        }
    }

    if(DEBUG) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                printf("%d", ans[i][j]);
            }
            printf("\n");
        }
    }


    if(DEBUG) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                printf(" (%d %d %d) ", z[i][j].x, z[i][j].y, z[i][j].s);
            }
            printf("\n");
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            vector<data> v;
            if(ans[i][j] == -1) {
                if(ans[i-1][j] != -1) {
                    if (!if_in_v(v, z[i-1][j])) {
                        final[i][j] += ans[i-1][j];
                        v.push_back(z[i-1][j]);
                    }
                }
                if(ans[i+1][j] != -1) {
                    if (!if_in_v(v, z[i+1][j])) {
                        final[i][j] += ans[i+1][j];
                        v.push_back(z[i+1][j]);
                    }
                }
                if(ans[i][j-1] != -1) {
                    if (!if_in_v(v, z[i][j-1])) {
                        final[i][j] += ans[i][j-1];
                        v.push_back(z[i][j-1]);
                    }
                }
                if(ans[i][j+1] != -1) {
                    if (!if_in_v(v, z[i][j+1])) {
                        final[i][j] += ans[i][j+1];
                        v.push_back(z[i][j+1]);
                    }
                }
                final[i][j] += 1;
                final[i][j] = final[i][j] % 10;
            }
            v.clear();
        }
    }

    if(DEBUG) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                printf("%d", final[i][j]);
            }
            printf("\n");
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(g[i][j] == '*') {
                g[i][j] = final[i+1][j+1] + 48;
            }
        }
    }

    for(int i=0; i<n; i++) {
        printf("%s\n", g[i]);
    }


    return 0;
}
