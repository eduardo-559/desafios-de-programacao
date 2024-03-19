#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int T, N;
    cin >> T;

    while (T--)
    {
        cin >> N;
        vector<int> A(N);
        unordered_map<int, int> freq;

        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
            ++freq[A[i]];
        }

        int max_freq = 0;
        for (const auto &pair : freq)
        {
            if (pair.second > max_freq)
            {
                max_freq = pair.second;
            }
        }

        int min_operations = N - max_freq;
        cout << min_operations << endl;
    }

    return 0;
}