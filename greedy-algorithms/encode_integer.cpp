#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        if (N == 0)
        {
            cout << 10 << endl;
            continue;
        }

        if (N == 1)
        {
            cout << 1 << endl;
            continue;
        }

        vector<int> digits;
        for (int d = 9; d >= 2; --d)
        {
            while (N % d == 0)
            {
                digits.push_back(d);
                N /= d;
            }
        }

        if (N > 1)
        {
            cout << -1 << endl;
        }
        else
        {
            reverse(digits.begin(), digits.end());
            for (int d : digits)
            {
                cout << d;
            }
            cout << endl;
        }
    }

    return 0;
}