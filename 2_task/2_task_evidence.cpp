#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
    


int main()
{
    std::ifstream input("data_prog_contest_problem_2.txt");
    int n;
    input >> n;
    std::vector<int> letters(n);
    for (auto& letter : letters)
    {
        input >> letter;
    }
    for (int i = 1; i <= 26; i++)
    {

        std::cout << i << ": " << std::find(letters.begin(), letters.end(), i) - letters.begin() << std::endl;
    }
    return 0;
}