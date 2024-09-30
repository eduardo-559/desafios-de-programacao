#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void buildTree(const vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(arr, start, mid, 2 * node + 1);
            buildTree(arr, mid + 1, end, 2 * node + 2);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int queryTree(int start, int end, int l, int r, int node) {
        if (r < start || l > end) {
            return INT_MAX;
        }
        if (l <= start && r >= end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftMin = queryTree(start, mid, l, r, 2 * node + 1);
        int rightMin = queryTree(mid + 1, end, l, r, 2 * node + 2);
        return min(leftMin, rightMin);
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, INT_MAX);
        buildTree(arr, 0, n - 1, 0);
    }

    int query(int l, int r) {
        return queryTree(0, n - 1, l, r, 0);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    SegmentTree segTree(arr);

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << segTree.query(a - 1, b - 1) << endl; // Ajustando para indexação baseada em 0
    }

    return 0;
}
