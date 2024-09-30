#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

double averageShortestPathLength(const vector<vector<int>>& graph, int n) {
    int totalPaths = 0;
    int totalLength = 0;

    for (int i = 1; i <= n; ++i) {
        vector<int> dist(n + 1, INF);
        queue<int> q;

        dist[i] = 0;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        for (int j = 1; j <= n; ++j) {
            if (i != j && dist[j] != INF) {
                totalPaths++;
                totalLength += dist[j];
            }
        }
    }

    return static_cast<double>(totalLength) / totalPaths;
}

int main() {
    int a, b, caseNumber = 1;

    while (true) {
        vector<vector<int>> graph(101);
        int maxNode = 0;

        while (cin >> a >> b && (a != 0 || b != 0)) {
            graph[a].push_back(b);
            maxNode = max(maxNode, max(a, b));
        }

        if (maxNode == 0) break;

        double averageLength = averageShortestPathLength(graph, maxNode);
        cout << "Case " << caseNumber++ << ": average length between pages = ";
        cout << fixed << setprecision(3) << averageLength << " clicks" << endl;
    }

    return 0;
}
