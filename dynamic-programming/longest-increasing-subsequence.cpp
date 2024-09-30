#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> longestIncreasingSubsequence(const vector<int>& nums) {
    vector<int> dp, pos;    // dp armazena o menor final de subsequências de cada tamanho
    vector<int> prev(nums.size(), -1); // Armazenar o índice do predecessor em LIS
    map<int, int> index_map; // Mapear valor para índice na subsequência dp

    for (int i = 0; i < nums.size(); ++i) {
        // Busca binária para encontrar o lugar para substituir em dp
        int j = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
        if (j == dp.size()) { // Se nums[i] é maior que todos em dp, adicione no fim
            dp.push_back(nums[i]);
            pos.push_back(i);
        } else {
            dp[j] = nums[i];
            pos[j] = i;
        }
        // Atualiza prev para rastrear o índice do predecessor
        if (j > 0) prev[i] = pos[j-1];
        index_map[nums[i]] = i; // Atualiza o mapeamento para o índice atual
    }

    // Reconstruindo a LIS pelo índice
    vector<int> lis_indices;
    int current = pos.back();
    while (current != -1) {
        lis_indices.push_back(current);
        current = prev[current];
    }
    reverse(lis_indices.begin(), lis_indices.end());
    
    return lis_indices;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vector<int> lis_indices = longestIncreasingSubsequence(nums);
        cout << lis_indices.size() << endl;
        for (int idx : lis_indices) {
            cout << idx << " ";
        }
        cout << endl;
    }
    return 0;
}
