#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int start, vector<vector<int>>& adj, vector<int>& teams) {
    queue<int> q;
    q.push(start);
    teams[start] = 1; // Começamos colorindo com o time 1

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (teams[neighbor] == -1) {
                // Se ainda não foi colorido, colorimos com a cor oposta
                teams[neighbor] = 3 - teams[node]; // Alterna entre 1 e 2
                q.push(neighbor);
            } else if (teams[neighbor] == teams[node]) {
                // Se já foi colorido e tem a mesma cor que o nó atual, não é possível
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> teams(n + 1, -1); // -1 significa não colorido

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (teams[i] == -1) {
            // Se o nó ainda não foi visitado, iniciamos uma BFS a partir dele
            if (!bfs(i, adj, teams)) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << teams[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
