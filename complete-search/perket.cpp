#include <iostream>
#include <vector>
#include <cmath>
#include <climits> // Para LLONG_MAX

int N;
std::vector<std::pair<long long, long long>> ingredients;
long long min_diff = LLONG_MAX;

void find_min_diff(int index, long long current_sourness, long long current_bitterness)
{
    if (index == N)
    {
        if (current_sourness != 1 || current_bitterness != 0)
        { // Certifica-se de que pelo menos um ingrediente foi usado
            min_diff = std::min(min_diff, std::abs(current_sourness - current_bitterness));
        }
        return;
    }

    // Incluir o ingrediente atual
    find_min_diff(index + 1, current_sourness * ingredients[index].first, current_bitterness + ingredients[index].second);

    // Não incluir o ingrediente atual
    find_min_diff(index + 1, current_sourness, current_bitterness);
}

int main()
{
    std::cin >> N;
    ingredients.resize(N);

    for (int i = 0; i < N; ++i)
    {
        std::cin >> ingredients[i].first >> ingredients[i].second;
    }

    find_min_diff(0, 1, 0); // A acidez inicial é 1 para permitir a multiplicação e a amargura é 0.
    std::cout << min_diff << std::endl;

    return 0;
}
