#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> can_sizes(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> can_sizes[i];
    }

    // Ordenar os tamanhos das latas para busca binária eficiente
    std::sort(can_sizes.begin(), can_sizes.end());

    long long total_waste = 0;

    for (int i = 0; i < m; ++i)
    {
        int required;
        std::cin >> required;

        // Encontrar a lata que mais se aproxima do valor necessário, sem ser menor
        auto it = std::lower_bound(can_sizes.begin(), can_sizes.end(), required);

        // Se encontramos um tamanho de lata adequado, calculamos o desperdício
        if (it != can_sizes.end())
        {
            total_waste += *it - required;
        }
    }

    std::cout << total_waste << '\n';

    return 0;
}