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

int main() {
    string s;
    cin >> s;

    vector<char> v;

    int res = 0;
    int impossible = 0;

    map<char, char> m;
    m['>'] = '<';
    m['}'] = '{';
    m[']'] = '[';
    m[')'] = '(';

    for(int i=0; i<s.size(); i++) {
        if(s[i] == '>' || s[i] == '}' || s[i] == ']' || s[i] == ')') {
            if(v.size() == 0) {
                impossible = 1;
                break;
            } else {

                if(v.back() == m.find(s[i])->second) {
                    v.pop_back();
                } else {
                    res++;
                    v.pop_back();
                }
            }
        } else {
            v.push_back(s[i]);
        }
    }

    if(v.size() != 0) {
        impossible = 1;
    }

    if(impossible) {
        cout << "Impossible" << endl;
    } else {
        cout << res << endl;
    }

}

// int main() {
//     string s;
//     cin >> s;

//     vector<char> v1;
//     vector<char> v2;
//     vector<char> v3;
//     vector<char> v4;

//     int res = 0;
//     int impossible = 0;

//     if(s.size() % 2 == 1) {
//         impossible = 1;
//     } else {
//         for(int i=0; i<s.size(); i++) {
//             if(s[i] == '<') {
//                 v1.push_back(s[i]);
//             }
//             if(s[i] == '{') {
//                 v2.push_back(s[i]);
//             }
//             if(s[i] == '[') {
//                 v3.push_back(s[i]);
//             }
//             if(s[i] == '(') {
//                 v4.push_back(s[i]);
//             }
//             if(s[i] == '>') {
//                 if(v1.size() == 0) {
//                     if(v2.size() == 0 && v3.size() == 0 && v4.size() == 0) {
//                         impossible = 1;
//                         break;
//                     } else {
//                         if(v2.size() != 0) {
//                             v2.pop_back();
//                             res++;
//                         } else if(v3.size() != 0) {
//                             v3.pop_back();
//                             res++;
//                         } else if(v4.size() != 0) {
//                             v4.pop_back();
//                             res++;
//                         }
//                     }
//                 } else {
//                     v1.pop_back();
//                 }
//             }
//             if(s[i] == '}') {
//                 if(v2.size() == 0) {
//                     if(v1.size() == 0 && v3.size() == 0 && v4.size() == 0) {
//                         impossible = 1;
//                         break;
//                     } else {
//                         if(v1.size() != 0) {
//                             v1.pop_back();
//                             res++;
//                         } else if(v3.size() != 0) {
//                             v3.pop_back();
//                             res++;
//                         } else if(v4.size() != 0) {
//                             v4.pop_back();
//                             res++;
//                         }
//                     }
//                 } else {
//                     v2.pop_back();
//                 }
//             }
//             if(s[i] == ']') {
//                 if(v3.size() == 0) {
//                     if(v2.size() == 0 && v1.size() == 0 && v4.size() == 0) {
//                         impossible = 1;
//                         break;
//                     } else {
//                         if(v2.size() != 0) {
//                             v2.pop_back();
//                             res++;
//                         } else if(v1.size() != 0) {
//                             v1.pop_back();
//                             res++;
//                         } else if(v4.size() != 0) {
//                             v4.pop_back();
//                             res++;
//                         }
//                     }
//                 } else {
//                     v3.pop_back();
//                 }
//             }
//             if(s[i] == ')') {
//                 if(v4.size() == 0) {
//                     if(v2.size() == 0 && v3.size() == 0 && v1.size() == 0) {
//                         impossible = 1;
//                         break;
//                     } else {
//                         if(v2.size() != 0) {
//                             v2.pop_back();
//                             res++;
//                         } else if(v3.size() != 0) {
//                             v3.pop_back();
//                             res++;
//                         } else if(v1.size() != 0) {
//                             v1.pop_back();
//                             res++;
//                         }
//                     }
//                 } else {
//                     v4.pop_back();
//                 }
//             }
//         }
//     }

//     if(v1.size() != 0 || v2.size() != 0 || v3.size() != 0 || v4.size() != 0) {
//         impossible = 1;
//     }

//     if(impossible) {
//         cout << "Impossible" << endl;
//     } else {
//         cout << res << endl;
//     }

//     return 0;
// }
