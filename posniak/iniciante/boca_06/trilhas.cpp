#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main()
{
    //_
    int entradas;
    cin >> entradas;
    int aux, k;
    pair<int, int> melhor = make_pair(0, INF);
    for (k = 0; k < entradas; k++)
    {
        int tam = 0;
        int esforco_ida = 0;
        int esforco_volta = 0;
        cin >> tam;
        vector<int> trilha;
        trilha.reserve(tam);

        for (int i = 0; i < tam; i++)
        {
            cin >> aux;
            trilha.push_back(aux);
        }

        for (int i = 0; i < tam - 1; i++)
        {
            if (trilha[i + 1] > trilha[i])
                esforco_ida += trilha[i + 1] - trilha[i];

            if (trilha[i] > trilha[i + 1])
                esforco_volta += trilha[i] - trilha[i + 1];
        }

        int esforco = min(esforco_ida, esforco_volta);

        if (esforco < melhor.second)
        {
            melhor = make_pair(k + 1, esforco);
        }
    }
    cout << melhor.first << endl;
    return 0;
}