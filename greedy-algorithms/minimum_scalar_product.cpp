#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função para calcular o produto escalar mínimo dos vetores
long long minScalarProduct(vector<int> &v1, vector<int> &v2)
{
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<int>());

    long long result = 0;
    for (size_t i = 0; i < v1.size(); ++i)
    {
        result += static_cast<long long>(v1[i]) * v2[i];
    }

    return result;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n;
        cin >> n;
        vector<int> v1(n), v2(n);

        for (int i = 0; i < n; ++i)
            cin >> v1[i];
        for (int i = 0; i < n; ++i)
            cin >> v2[i];

        cout << "Case #" << t << ": " << minScalarProduct(v1, v2) << endl;
    }

    return 0;
}