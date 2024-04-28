#include <bits/stdc++.h>

using namespace std;

int main()
{
    int dancers;
    cin >> dancers;

    bitset<26> routine[dancers];

    for (int i = 0; i < dancers; i++)
    {
        string s;
        cin >> s;

        for (auto c : s)
        {
            routine[i].set(c - 'A');
        }
    }

    vector<int> order(dancers);

    for (int i = 0; i < dancers; i++)
    {
        order[i] = i;
    }

    int min_trades = 26 * dancers;

    do
    {
        int cont = 0;

        for (int i = 1; i < dancers; i++)
        {
            bitset<26> res = routine[order[i]] & routine[order[i - 1]];

            cont += res.count();
        }

        min_trades = min(min_trades, cont);

    } while (next_permutation(order.begin(), order.end()));

    cout << min_trades << "\n";
}