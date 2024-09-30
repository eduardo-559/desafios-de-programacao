#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> forest(n + 1, vector<int>(n + 1, 0));

    // Lendo a floresta e construindo a soma prefixada bidimensional
    for (int i = 1; i <= n; ++i) {
        string line;
        cin >> line;
        for (int j = 1; j <= n; ++j) {
            forest[i][j] = (line[j - 1] == '*') ? 1 : 0;
            forest[i][j] += forest[i - 1][j] + forest[i][j - 1] - forest[i - 1][j - 1];
        }
    }

    // Processando as queries
    for (int i = 0; i < q; ++i) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        int result = forest[y2][x2]
                     - (x1 > 1 ? forest[y2][x1 - 1] : 0)
                     - (y1 > 1 ? forest[y1 - 1][x2] : 0)
                     + (x1 > 1 && y1 > 1 ? forest[y1 - 1][x1 - 1] : 0);

        cout << result << endl;
    }

    return 0;
}
