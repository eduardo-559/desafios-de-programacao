#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;

    while (cin >> n >> m && (n != 0 || m != 0))
    {
        vector<int> dragonHeads(n);
        vector<int> knightHeights(m);

        for (int i = 0; i < n; ++i)
        {
            cin >> dragonHeads[i];
        }

        for (int i = 0; i < m; ++i)
        {
            cin >> knightHeights[i];
        }

        sort(dragonHeads.begin(), dragonHeads.end());
        sort(knightHeights.begin(), knightHeights.end());

        int cost = 0;
        int knightsUsed = 0;
        bool doomed = false;

        for (int head : dragonHeads)
        {
            while (knightsUsed < m && knightHeights[knightsUsed] < head)
            {
                ++knightsUsed;
            }

            if (knightsUsed == m)
            {
                doomed = true;
                break;
            }

            cost += knightHeights[knightsUsed];
            ++knightsUsed;
        }

        if (doomed)
        {
            cout << "Loowater is doomed!" << endl;
        }
        else
        {
            cout << cost << endl;
        }
    }

    return 0;
}