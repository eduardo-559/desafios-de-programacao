#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void topologicalSort(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& topoStack) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            topologicalSort(neighbor, adj, visited, topoStack);
        }
    }
    topoStack.push(node);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    stack<int> topoStack;
    vector<bool> visited(n + 1, false);

    // Ordenamento Topológico
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            topologicalSort(i, adj, visited, topoStack);
        }
    }

    vector<int> dist(n + 1, -1);  // -1 indica que a cidade não foi alcançada
    vector<int> parent(n + 1, -1);
    dist[1] = 0;

    // DP para calcular o caminho mais longo
    while (!topoStack.empty()) {
        int node = topoStack.top();
        topoStack.pop();

        if (dist[node] != -1) {  // Se o nó é alcançável
            for (int neighbor : adj[node]) {
                if (dist[neighbor] < dist[node] + 1) {
                    dist[neighbor] = dist[node] + 1;
                    parent[neighbor] = node;
                }
            }
        }
    }

    if (dist[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dist[n] + 1 << endl;
        vector<int> path;
        for (int v = n; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
