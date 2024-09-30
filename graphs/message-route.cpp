#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int n, vector<vector<int>>& adj) {
    vector<int> parent(n + 1, -1); // Para armazenar o pai de cada nó no caminho mais curto
    vector<bool> visited(n + 1, false); // Para marcar os nós visitados
    queue<int> q;

    q.push(1);
    visited[1] = true;
    parent[1] = 0; // Raiz (não tem pai, então definimos como 0)

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node; // Define o pai do vizinho como o nó atual
                q.push(neighbor);

                // Se alcançamos o último nó, paramos
                if (neighbor == n) {
                    break;
                }
            }
        }
    }

    return parent;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent = bfs(n, adj);

    if (parent[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        for (int at = n; at != 0; at = parent[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for (int city : path) {
            cout << city << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
