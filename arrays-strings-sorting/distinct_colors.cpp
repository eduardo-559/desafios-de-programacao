#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        int N;
        std::cin >> N;
        std::vector<int> A(N);

        for (int i = 0; i < N; ++i)
        {
            std::cin >> A[i];
        }

        // O número mínimo de caixas é o máximo número de bolas de qualquer cor
        int min_boxes = *std::max_element(A.begin(), A.end());
        std::cout << min_boxes << std::endl;
    }

    return 0;
}