#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int calculateDistance(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int shortestPath(int current, int visited, vector<pair<int, int>>& points, vector<vector<int>>& memo) {
    if (visited == (1 << points.size()) - 1) {
        return calculateDistance(points[current], points[0]); // Return to start
    }

    if (memo[current][visited] != -1) {
        return memo[current][visited];
    }

    int minPath = numeric_limits<int>::max();
    for (int i = 0; i < points.size(); i++) {
        if (!(visited & (1 << i))) { // If not visited
            int distance = calculateDistance(points[current], points[i]);
            int path = distance + shortestPath(i, visited | (1 << i), points, memo);
            minPath = min(minPath, path);
        }
    }
    return memo[current][visited] = minPath;
}

int main() {
    int scenarios;
    cin >> scenarios;
    while (scenarios--) {
        int width, height;
        cin >> width >> height;
        int startX, startY;
        cin >> startX >> startY;
        int beepers;
        cin >> beepers;
        vector<pair<int, int>> points;
        points.emplace_back(startX, startY); // Start position

        for (int i = 0; i < beepers; i++) {
            int x, y;
            cin >> x >> y;
            points.emplace_back(x, y);
        }

        vector<vector<int>> memo(points.size(), vector<int>((1 << points.size()), -1));
        int minDistance = shortestPath(0, 1, points, memo);
        cout << "The shortest path has length " << minDistance << endl;
    }
    return 0;
}
