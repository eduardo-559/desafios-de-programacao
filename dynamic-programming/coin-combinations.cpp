#include <iostream>
#include <vector>
#include <limits>

const int MOD = 1000000007; // Módulo dado pelo problema

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }

    std::vector<int> dp(x + 1, 0);
    dp[0] = 1; // Há uma maneira de formar a soma 0: não usando nenhuma moeda

    // Processar cada soma possível até x
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= coins[j]) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD; // Atualiza o número de maneiras
            }
        }
    }

    std::cout << dp[x] << std::endl; // Número de maneiras de formar a soma x, mod 10^9 + 7

    return 0;
}
