#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    int n = grid.size();
    int m = grid[0].size();
    
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#' || visited[x][y]) {
        return;
    }

    visited[x][y] = true;

    // Mover para as quatro direções: cima, baixo, esquerda, direita
    dfs(x - 1, y, grid, visited);
    dfs(x + 1, y, grid, visited);
    dfs(x, y - 1, grid, visited);
    dfs(x, y + 1, grid, visited);
}

int countRooms(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int room_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                // Iniciando uma nova DFS a partir de um piso não visitado
                dfs(i, j, grid, visited);
                room_count++;
            }
        }
    }

    return room_count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << countRooms(grid) << endl;

    return 0;
}
