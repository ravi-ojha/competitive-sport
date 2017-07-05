#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int const size = 5;
    int Scores[size] = {9, 22, 76, 10, 11};

    std::sort(Scores, Scores+size, greater<int>());

    for(int i = 0; i<size; ++i)
        std::cout << Scores[i] << " ";
    std::cout << std::endl;
}
