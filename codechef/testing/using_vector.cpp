#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
//    vector <int> a;
//    vector <int> :: iterator it;
//    int n;
//    scanf(" %d",&n);
//    while(n--)
//    {
//        int tmp;
//        scanf(" %d",&tmp);
//        a.push_back(tmp);
//    }
//    it = a.begin();
//    while(it!=a.end())
//    {
//        printf(" %d",(*it));
//        it++;
//    }
    int m,i,n;
    scanf(" %d",&m);
    vector <int> a[10];
    vector <int> :: iterator itr;
    for(i=0;i<m;i++)
    {
        scanf(" %d",&n);
        while(n--)
        {
            int tmp;
            scanf(" %d",&tmp);
            a[i].push_back(tmp);
        }
    }
    for(i=0;i<m;i++)
    {
        printf("#%d: ",i);
        itr = a[i].begin();
        while(itr != a[i].end())
        {
            printf(" %d",(*itr));
            itr++;
        }
        printf("\n");
    }
    return 0;
}
