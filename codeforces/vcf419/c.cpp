#include <bits/stdc++.h>

// Some constants that are frequently used
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

// Something to print to console and debug
#define DEBUG false
#define CONSOLE(x) if(DEBUG) {cout << '>' << #x << ':' << x << endl;}

using namespace std;

string my_to_string(string s, int i) {
    ostringstream oss;
    oss << s << i;
    string var = oss.str();
    return var;
}

int main() {
    int n, m;
    scanf(" %d %d",&n, &m);
    int grid[110][110];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf(" %d",&grid[i][j]);
        }
    }



    if(m > n) {
        // Then we go row wise first
        int min_in_each_row[110] = {0};
        for(int i=0; i<n; i++) {
            int min_in_row = 1000000;
            for(int j=0; j<m; j++) {
                min_in_row = min(min_in_row, grid[i][j]);
            }
            min_in_each_row[i] = min_in_row;
            for(int j=0; j<m; j++) {
                grid[i][j] = grid[i][j] - min_in_row;
            }
        }

        // go column wise now
        int min_in_each_col[110] = {0};
        for(int i=0; i<m; i++) {
            int min_in_col = 1000000;
            for(int j=0; j<n; j++) {
                min_in_col = min(min_in_col, grid[j][i]);
            }
            min_in_each_col[i] = min_in_col;
            for(int j=0; j<n; j++) {
                grid[j][i] = grid[j][i] - min_in_col;
            }
        }

        // Check if grid has become entirely 0
        int flag = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(DEBUG) {printf("%d ", grid[i][j]);}
                if(grid[i][j] != 0) {
                    flag = 1;
                    break;
                }
            }
            if(DEBUG) {printf("\n");}
        }

        if(flag) {
            printf("-1\n");
        } else {
            vector <string> v;
            for(int i=0; i<110; i++) {
                while(min_in_each_row[i]--) {
                    string res = my_to_string("row ", i+1);
                    v.push_back(res);
                }
            }

            for(int i=0; i<110; i++) {
                while(min_in_each_col[i]--) {
                    string res = my_to_string("col ", i+1);
                    v.push_back(res);
                }
            }

            int count = v.size();
            printf("%d\n", count);
            for(int i=0; i<count; i++) {
                cout << v[i] << endl;
            }
        }

    } else {
        // Then we go col wise first
        int min_in_each_col[110] = {0};
        for(int i=0; i<m; i++) {
            int min_in_col = 1000000;
            for(int j=0; j<n; j++) {
                min_in_col = min(min_in_col, grid[j][i]);
            }
            min_in_each_col[i] = min_in_col;
            for(int j=0; j<n; j++) {
                grid[j][i] = grid[j][i] - min_in_col;
            }
        }

        // go row wise now
        int min_in_each_row[110] = {0};
        for(int i=0; i<n; i++) {
            int min_in_row = 1000000;
            for(int j=0; j<m; j++) {
                min_in_row = min(min_in_row, grid[i][j]);
            }
            min_in_each_row[i] = min_in_row;
            for(int j=0; j<m; j++) {
                grid[i][j] = grid[i][j] - min_in_row;
            }
        }

        // Check if grid has become entirely 0
        int flag = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(DEBUG) {printf("%d ", grid[i][j]);}
                if(grid[i][j] != 0) {
                    flag = 1;
                    break;
                }
            }
            if(DEBUG) {printf("\n");}
        }

        if(flag) {
            printf("-1\n");
        } else {
            vector <string> v;
            for(int i=0; i<110; i++) {
                while(min_in_each_row[i]--) {
                    string res = my_to_string("row ", i+1);
                    v.push_back(res);
                }
            }

            for(int i=0; i<110; i++) {
                while(min_in_each_col[i]--) {
                    string res = my_to_string("col ", i+1);
                    v.push_back(res);
                }
            }

            int count = v.size();
            printf("%d\n", count);
            for(int i=0; i<count; i++) {
                cout << v[i] << endl;
            }
        }
    }

    return 0;
}
