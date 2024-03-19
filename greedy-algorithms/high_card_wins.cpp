#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // Abrir arquivos para leitura e escrita
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    int N;
    std::cin >> N;

    std::vector<int> elsiesCards(N);
    std::vector<int> bessiesCards;
    std::vector<bool> taken(2 * N + 1, false);

    for (int i = 0; i < N; ++i)
    {
        std::cin >> elsiesCards[i];
        taken[elsiesCards[i]] = true;
    }

    for (int i = 1; i <= 2 * N; ++i)
    {
        if (!taken[i])
        {
            bessiesCards.push_back(i);
        }
    }

    std::sort(elsiesCards.begin(), elsiesCards.end());

    int points = 0, j = 0;
    for (int i = 0; i < N && j < N; i++)
    {
        if (bessiesCards[i] > elsiesCards[j])
        {
            points++;
            j++;
        }
    }

    std::cout << points << std::endl;

    // Fechar arquivos
    fclose(stdin);
    fclose(stdout);

    return 0;
}