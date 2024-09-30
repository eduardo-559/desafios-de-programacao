#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int editDistance(const string& s1, const string& s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Inicializando a tabela de programação dinâmica
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;  // Custos de deletar todos os caracteres de s1
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;  // Custos de adicionar todos os caracteres em s2
    }

    // Preenchendo a tabela dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // Caracteres iguais, sem custo extra
            } else {
                dp[i][j] = min({dp[i - 1][j] + 1,    // Deletar um caractere de s1
                                dp[i][j - 1] + 1,    // Inserir um caractere em s2
                                dp[i - 1][j - 1] + 1 // Substituir um caractere
                               });
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << editDistance(s1, s2) << endl;
    return 0;
}
