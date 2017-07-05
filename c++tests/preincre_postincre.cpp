#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int i = 5;
    printf("%d\n",i++ + ++i); //Undefined Behaviour
    int j = 2;
    j = (j++);
    printf("%d",j);
    return 0;
}
