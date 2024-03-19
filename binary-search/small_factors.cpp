#include <iostream>
#include <cmath>
#include <algorithm>

// Função para calcular o próximo número de 2^i * 3^j que é maior ou igual a m
unsigned long long Next23(unsigned long long m)
{
    unsigned long long best = 1ULL << 62; // Inicializa com um número grande

    // Encontrar o limite superior de i e j, considerando as potências de 2 e 3
    int max_i = static_cast<int>(std::log(m) / std::log(2)) + 1;
    int max_j = static_cast<int>(std::log(m) / std::log(3)) + 1;

    // Tentar todas as combinações possíveis de i e j
    for (int i = 0; i <= max_i; ++i)
    {
        for (int j = 0; j <= max_j; ++j)
        {
            unsigned long long candidate = static_cast<unsigned long long>(std::pow(2, i)) *
                                           static_cast<unsigned long long>(std::pow(3, j));
            if (candidate >= m)
            {
                best = std::min(best, candidate);
            }
        }
    }

    return best;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long long m;
    while (std::cin >> m && m != 0)
    {
        std::cout << Next23(m) << std::endl;
    }

    return 0;
}