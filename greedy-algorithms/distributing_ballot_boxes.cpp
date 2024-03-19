#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Função para verificar se é possível distribuir as urnas de forma que o máximo
// de pessoas por urna seja 'max_ppl' ou menos.
bool isPossible(const vector<int> &populations, int boxes, int max_ppl)
{
    int needed_boxes = 0;
    for (int pop : populations)
    {
        needed_boxes += (pop + max_ppl - 1) / max_ppl; // Arredondamento para cima
    }
    return needed_boxes <= boxes;
}

int main()
{
    int N, B;
    while (cin >> N >> B, N != -1 && B != -1)
    {
        vector<int> populations(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> populations[i];
        }

        // Busca binária para encontrar o número mínimo de pessoas por urna
        int low = 1, high = *max_element(populations.begin(), populations.end());
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(populations, B, mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << low << endl;
    }
    return 0;
}