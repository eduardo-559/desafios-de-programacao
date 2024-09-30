#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> arr(n + 1, 0);  // Usando long long para evitar overflow

    // Lendo o array e construindo a soma prefixada
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        arr[i] = arr[i - 1] + x;
    }

    // Processando as queries
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << endl;
    }

    return 0;
}
