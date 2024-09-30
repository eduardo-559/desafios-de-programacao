#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> components;

    // Encontrando todos os componentes conectados
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components.push_back(i);
            dfs(i, adj, visited);
        }
    }

    // Número de estradas necessárias para conectar todos os componentes
    int k = components.size() - 1;
    cout << k << endl;

    // Imprimindo as estradas necessárias para conectar os componentes
    for (int i = 1; i < components.size(); i++) {
        cout << components[i - 1] << " " << components[i] << endl;
    }

    return 0;
}
