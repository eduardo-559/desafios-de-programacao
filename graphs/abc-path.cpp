#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h, w;
vector<vector<char>> grid;
vector<vector<int>> dp;
vector<int> dx = {1, 1, 1, 0, 0, -1, -1, -1};
vector<int> dy = {0, 1, -1, 1, -1, 0, 1, -1};

int dfs(int x, int y) {
    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    int max_len = 1;  // Começamos com o comprimento 1 (a célula atual)
    
    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if (newX >= 0 && newX < h && newY >= 0 && newY < w && grid[newX][newY] == grid[x][y] + 1) {
            max_len = max(max_len, 1 + dfs(newX, newY));
        }
    }

    return dp[x][y] = max_len;
}

int main() {
    int case_num = 1;

    while (true) {
        cin >> h >> w;
        if (h == 0 && w == 0) {
            break;
        }

        grid = vector<vector<char>>(h, vector<char>(w));
        dp = vector<vector<int>>(h, vector<int>(w, -1));
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
            }
        }

        int max_path = 0;
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 'A') {
                    max_path = max(max_path, dfs(i, j));
                }
            }
        }

        cout << "Case " << case_num << ": " << max_path << endl;
        case_num++;
    }

    return 0;
}
