#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> perm;
vector<bool> used;
vector<int> sun;
int g[12][12];
map<string, int> color;
map<int, string> rev;
int cont;

void gera(int i, int n)
{

    if (i == n)
    {
        cont++;
        if (cont == 1)
        {
            for (int j = 0; j < n; j++)
                sun[j] = perm[j];
        }
    }
    else if (i == 0)
    {

        for (int j = 0; j < n; j++)
        {
            if (!used[j])
            {
                perm[i] = v[j];
                used[j] = true;
                gera(i + 1, n);
                used[j] = false;
            }
        }
    }
    else
    {

        int anterior = perm[i - 1];
        for (int j = 0; j < n; j++)
        {
            if (!used[j] && g[anterior][v[j]] == 0)
            {
                perm[i] = v[j];
                used[j] = true;
                gera(i + 1, n);
                used[j] = false;
            }
        }
    }
}

int main()
{

    int t{0};
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        color.clear();
        rev.clear();

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            color[s] = i;
            rev[i] = s;
        }

        int m;
        cin >> m;

        memset(g, 0, sizeof(g));
        for (int i = 0; i < m; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            g[color[s1]][color[s2]] = 1;
            g[color[s2]][color[s1]] = 1;
        }

        v.assign(n, 0);
        used.assign(n, false);

        for (int i = 0; i < n; i++)
        {
            v[i] = i;
        }

        perm.assign(n, 0);
        sun.assign(n, 0);
        cont = 0;
        gera(0, n);

        cout << cont << endl;
        cout << rev[sun[0]];
        for (int i = 1; i < n; i++)
            cout << " " << rev[sun[i]];
        cout << "\n";
    }
}