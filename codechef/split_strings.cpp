#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
    int t;
    scanf(" %d",&t);
    getchar();
    while(t--)
    {
        std::string sentence;
        std::vector<string>::iterator j;
//        string sentence = "Now and  i  a Now";
        std::getline(cin, sentence);
        istringstream iss(sentence);
    //    copy(istream_iterator<string>(iss),
    //             istream_iterator<string>(),
    //             ostream_iterator<string>(cout, "\n"));
        vector<string> tokens;
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter<vector<string> >(tokens));
        std::sort(tokens.begin(), tokens.end());
        tokens.erase(std::unique(tokens.begin(), tokens.end()), tokens.end());
        int n = tokens.size();
        printf("%d\n",n);
    }
    return 0;
}
