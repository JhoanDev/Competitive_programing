#include <bits/stdc++.h>

using namespace std;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

bool compativel(const unordered_set<int>& compativeis, const vector<unordered_set<int>>& blacklist, int integrante)
{
    for (auto& c : compativeis)
    {
        if (blacklist[integrante].count(c))
        {
            return false;
        }
    }
    return true;
}

int maximo(int a, int b)
{
    return (a > b) ? a : b;
}

void max_profundidade(unordered_set<int>& compativeis, int ult_inserido, int max, const vector<unordered_set<int>>& blacklist, int& melhor_global)
{

    int atual = compativeis.size();
    melhor_global = maximo(melhor_global, atual);
    int restantes = max - ult_inserido;
    if (atual + restantes <= melhor_global)
        return;
    for (int i = ult_inserido + 1; i <= max; i++)
    {
        if (compativel(compativeis, blacklist, i))
        {
            compativeis.insert(i);
            max_profundidade(compativeis, i, max, blacklist, melhor_global);
            compativeis.erase(i);
        }
    }
    return;
}

int main()
{
    _ int qnt_alunos, i, teste = 1;
    while (cin >> qnt_alunos && qnt_alunos)
    {
        vector<unordered_set<int>> blacklist(qnt_alunos + 1);
        for (i = 1; i <= qnt_alunos; i++)
        {
            int aux;
            while (cin >> aux && aux)
            {
                blacklist[i].insert(aux);
                blacklist[aux].insert(i);
            }
        }

        int melhor = 0;

        unordered_set<int> compativeis;
        max_profundidade(compativeis, 0, qnt_alunos, blacklist, melhor);

        cout << "Teste " << teste++ << endl;
        cout << melhor << endl
             << endl;
    }

    return 0;
}