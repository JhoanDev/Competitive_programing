#include <bits/stdc++.h>

using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

int main()
{
    fastio;
    string ass, vit;
    map<string, int> lista;
    while (cin >> ass >> vit)
    {
        lista[vit] = -1;
        if (lista[ass] != -1)
        {
            lista[ass]++;
        }
    }

    cout << "HALL OF MURDERERS" << endl;
    for (auto& a : lista)
    {
        if (a.second != -1)
        {
            cout << a.first << " " << a.second << endl;
        }
    }
    return 0;
}