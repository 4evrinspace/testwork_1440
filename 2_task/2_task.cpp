#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
    


int main()
{
    std::ifstream input("data_prog_contest_problem_2.txt");
    int n;
    input >> n;
    bool preented_letters[26] = {false};
    int number_of_presented_letters = 0;
    int i = 0;
    for (; number_of_presented_letters < 26 && i < n; i++)
    {
        int elem;
        input >> elem;
        if (1 <= elem && elem <= 26 && !preented_letters[elem - 1])
        {
            preented_letters[elem - 1] = true;
            number_of_presented_letters++;
        }
    }
    if (number_of_presented_letters == 26)
    {
        std::cout << i << std::endl;
    }
    else
    {
        std::cout << "NONE" << std::endl;
    }
    return 0;
}