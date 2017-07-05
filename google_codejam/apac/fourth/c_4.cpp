# include<cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include<iostream>
using namespace std;
# define MAX_SIZE 100

void _printParenthesis(int pos, int n, int open, int close);

int a[12] = {1,1,2,5,14,42,132,429,1430,4862,16796};
void printParenthesis(int n)
{
  if(n > 0)
     _printParenthesis(0, n, 0, 0);
  return;
}
vector <string> s;
void _printParenthesis(int pos, int n, int open, int close)
{
  static char str[MAX_SIZE];

  if(close == n)
  {
    //printf("%s \n", str);
    string tmp = string(str);
    s.push_back(tmp);
    return;
  }
  else
  {
    if(open > close) {
        str[pos] = ')';
        _printParenthesis(pos+1, n, open, close+1);
    }
    if(open < n) {
       str[pos] = '(';
       _printParenthesis(pos+1, n, open+1, close);
    }
  }
}

/* driver program to test above functions */
int main()
{
  int t;
  scanf(" %d",&t);
  for(int tt = 1;tt<=t;tt++)
  {
    s.clear();
    int n;
    long long k;
    scanf(" %d %lld",&n,&k);
    printParenthesis(n);
    if(k > a[n])
    {
      printf("Case #%d: Doesn't Exist!\n",tt);
    }
    else
    {
      //printf("Case #%d: %s",s[a[n] - k]);
      sort(s.begin(),s.end());
      cout << "Case #" <<tt<<": " <<s[k-1] << endl;
    }
  }

  return 0;
}
