#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int to, weight;
};

void dijkstra(int n, vector<vector<Edge>>& adj) {
    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[1] = 0;  // Distância da cidade 1 para ela mesma é 0
    pq.push({0, 1});  // Começamos a partir da cidade 1

    while (!pq.empty()) {
        long long d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d != dist[node]) continue;

        for (Edge edge : adj[node]) {
            if (dist[node] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[node] + edge.weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dijkstra(n, adj);

    return 0;
}
