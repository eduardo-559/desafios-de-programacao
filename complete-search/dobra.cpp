#include <bits/stdc++.h>

typedef long long int ll;
using namespace std;
string s;

bool isVogal(char c)
{
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

ll completa(int i, int num_l, int num_v, int num_c)
{
    if (num_v == 3 || num_c == 3)
        return 0;
    if (i == s.size())
    {
        if (num_l >= 1)
            return 1;
        return 0;
    }
    else
    {
        if (isVogal(s[i]))
            return completa(i + 1, num_l, num_v + 1, 0);
        else if (s[i] == '_')
            return 5 * completa(i + 1, num_l, num_v + 1, 0) +
                   20 * completa(i + 1, num_l, 0, num_c + 1) +
                   completa(i + 1, num_l + 1, 0, num_c + 1);
        else
        {
            if (s[i] == 'L')
                return completa(i + 1, num_l + 1, 0, num_c + 1);
            else
                return completa(i + 1, num_l, 0, num_c + 1);
        }
    }
}

int main()
{
    cin >> s;
    cout << completa(0, 0, 0, 0);
    return 0;
}
