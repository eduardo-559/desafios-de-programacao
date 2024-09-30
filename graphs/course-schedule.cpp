#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int n, const vector<vector<int>>& adj, vector<int>& in_degree) {
    queue<int> q;
    vector<int> order;

    // Colocar todos os nós com grau de entrada 0 na fila
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        // Para cada vizinho, reduza o grau de entrada e se chegar a 0, coloque na fila
        for (int neighbor : adj[node]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Se a ordenação topológica não tem todos os nós, existe um ciclo
    if (order.size() != n) {
        return {};
    }
    return order;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    vector<int> order = topoSort(n, adj, in_degree);

    if (order.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
