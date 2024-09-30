#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n + 1, 0);

    // Construindo o array de prefix XOR
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        arr[i] = arr[i - 1] ^ x;
    }

    // Processando as queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        int result = arr[b] ^ arr[a - 1];
        cout << result << endl;
    }

    return 0;
}
