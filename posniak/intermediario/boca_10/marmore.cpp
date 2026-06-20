#include <bits/stdc++.h>

using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int main()
{
    fastio;
    int marmores, consultas;
    int testes = 1;
    while ((cin >> marmores >> consultas) && (consultas || marmores))
    {
        cout << "CASE# " << testes++ << ":" << endl;
        vector<int> lista_mar;
        int m, c, id;
        lista_mar.reserve(marmores);
        for (size_t i = 0; i < marmores; ++i)
        {
            cin >> m;
            lista_mar.push_back(m);
        }
        sort(all(lista_mar));
        for (size_t i = 0; i < consultas; ++i)
        {
            cin >> c;
            auto it = lower_bound(all(lista_mar), c);
            if (it != lista_mar.end() && *it == c)
            {
                id = it - lista_mar.begin();
                cout << c << " found at " << id + 1 << endl;
            }
            else
            {
                cout << c << " not found" << endl;
            }
        }
    }

    return 0;
}