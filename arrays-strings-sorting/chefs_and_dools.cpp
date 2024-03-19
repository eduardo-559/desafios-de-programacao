#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int T, N, type;
    cin >> T;

    while (T--)
    {
        cin >> N;
        unordered_map<int, int> doll_counts;

        for (int i = 0; i < N; ++i)
        {
            cin >> type;
            ++doll_counts[type];
        }

        for (const auto &pair : doll_counts)
        {
            if (pair.second % 2 != 0)
            {
                cout << pair.first << endl;
                break;
            }
        }
    }

    return 0;
}