#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minSteps(int n) {
    vector<bool> visited(n+1, false);
    queue<pair<int, int>> q; // pair of current number and steps
    q.push({n, 0});
    visited[n] = true;

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        if (current == 0) {
            return steps;
        }

        // Iterate over each digit in the current number
        int temp = current;
        while (temp > 0) {
            int digit = temp % 10;
            temp /= 10;
            if (digit > 0 && current - digit >= 0 && !visited[current - digit]) {
                q.push({current - digit, steps + 1});
                visited[current - digit] = true;
            }
        }
    }

    return -1; // should never be reached
}

int main() {
    int n;
    cin >> n;
    cout << minSteps(n) << endl;
    return 0;
}
