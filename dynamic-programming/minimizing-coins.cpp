#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }

    // Usando um vetor para armazenar o mínimo de moedas necessárias para cada soma até x
    std::vector<int> dp(x + 1, std::numeric_limits<int>::max());
    dp[0] = 0; // Não precisamos de moedas para fazer a soma zero

    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= coins[j] && dp[i - coins[j]] != std::numeric_limits<int>::max()) {
                dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // Se dp[x] ainda é o valor máximo, significa que não é possível formar a soma x
    if (dp[x] == std::numeric_limits<int>::max()) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << dp[x] << std::endl;
    }

    return 0;
}
