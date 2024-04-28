#include <iostream>
#include <vector>
#include <map>

int findWinner(const std::vector<int> &rolls)
{
    std::map<int, int> frequency;
    std::map<int, int> index;

    // Contar a frequência de cada número e armazenar o último índice onde cada número foi visto
    for (int i = 0; i < rolls.size(); ++i)
    {
        frequency[rolls[i]]++;
        index[rolls[i]] = i + 1;
    }

    int winnerIndex = -1;
    int maxUniqueRoll = -1;

    // Identificar o maior número único
    for (const auto &elem : frequency)
    {
        if (elem.second == 1 && elem.first > maxUniqueRoll)
        {
            maxUniqueRoll = elem.first;
            winnerIndex = index[elem.first];
        }
    }

    return winnerIndex;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> rolls(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> rolls[i];
    }

    int winnerIndex = findWinner(rolls);

    if (winnerIndex == -1)
    {
        std::cout << "none" << std::endl;
    }
    else
    {
        std::cout << winnerIndex << std::endl;
    }

    return 0;
}
