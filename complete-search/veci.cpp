#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string X;
    std::cin >> X;

    // Encontre a próxima permutação maior que o número atual
    bool found = std::next_permutation(X.begin(), X.end());

    // Se a próxima permutação existir e for maior que o número atual, imprima-a
    // Caso contrário, imprima 0
    if (found)
    {
        std::cout << X << std::endl;
    }
    else
    {
        std::cout << "0" << std::endl;
    }

    return 0;
}
