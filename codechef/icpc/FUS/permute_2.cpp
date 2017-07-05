#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    std::string sequence;

    std::cout << "Sequence: ";
    std::cin >> sequence;

    std::cout << "Sorting " << sequence << "..." << std::endl;

    std::sort(sequence.begin(), sequence.end());

    std::cout << "Done! This is permutation 0." << std::endl;

    int count = 0;
    std::cout << count++ << ": " << sequence << std::endl;
    while (std::next_permutation(sequence.begin(), sequence.end()))
    {
        std::cout << count++ << ": " << sequence << std::endl;
    }
}
