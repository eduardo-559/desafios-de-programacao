#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int weight;
};

void dijkstra(int n, int S, int T, vector<vector<Edge>>& adj, int case_num) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[S] = 0;
    pq.push({0, S});
    
    while (!pq.empty()) {
        auto [curr_dist, node] = pq.top();
        pq.pop();
        
        if (curr_dist > dist[node]) continue;
        
        for (auto& edge : adj[node]) {
            int next = edge.to;
            int new_dist = curr_dist + edge.weight;
            
            if (new_dist < dist[next]) {
                dist[next] = new_dist;
                pq.push({new_dist, next});
            }
        }
    }
    
    // Imprimimos a resposta para o caso atual
    cout << "Case #" << case_num << ": ";
    if (dist[T] == INT_MAX) {
        cout << "unreachable" << endl;
    } else {
        cout << dist[T] << endl;
    }
}

int main() {
    int N;
    cin >> N;  // Número de casos de teste
    
    for (int case_num = 1; case_num <= N; case_num++) {
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        
        vector<vector<Edge>> adj(n);
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        dijkstra(n, S, T, adj, case_num);
    }
    
    return 0;
}
