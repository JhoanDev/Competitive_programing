#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

int main()
{
    //_
    int s, p, teste = 1;
    while (cin >> s >> p && p != s && s != 0)
    {
        cout << "Teste " << teste++ << endl;

        vector<pair<int, int>> intervalos;
        intervalos.reserve(p);

        int aux1, aux2;

        for (int i = 0; i < p; i++)
        {
            cin >> aux1 >> aux2;
            intervalos.push_back(make_pair(aux1, aux2));
        }

        sort(intervalos.begin(), intervalos.end());

        vector<pair<int, int>> intervalos_saida;
        int ini = intervalos.at(0).first, fim = intervalos.at(0).second;

        for (auto& aux : intervalos)
        {
            if (aux.second > fim)
            {
                if (aux.first <= fim)
                {
                    fim = aux.second;
                }
                else
                {
                    intervalos_saida.push_back(make_pair(ini, fim));
                    ini = aux.first;
                    fim = aux.second;
                }
            }
        }
        intervalos_saida.push_back(make_pair(ini, fim));

        for (auto& aux : intervalos_saida)
        {
            cout << aux.first << " " << aux.second << "\n";
        }
    }

    return 0;
}