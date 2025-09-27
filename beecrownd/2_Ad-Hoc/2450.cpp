#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    _ int linhas, colunas, i, j;
    cin >> linhas >> colunas;
    vector<vector<int>> matriz(linhas, vector<int>(colunas));
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            cin >> matriz[i][j];
        }
    }
    vector<int> pos_diferente(linhas, colunas);
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            if (matriz[i][j] != 0)
            {
                pos_diferente[i] = j;
                break;
            }
        }
    }
    bool escada = true;
    int aux = linhas;
    for (i = 0; i < linhas - 1; i++)
    {
        if (pos_diferente[i] >= pos_diferente[i + 1])
        {
            escada = false;
            break;
        }
        if (pos_diferente[i + 1] == colunas)
        {
            aux = i + 1;
            break;
        }
    }
    for (i = aux; i < linhas; i++)
    {
        if (pos_diferente[i] != colunas)
        {
            escada = false;
            break;
        }
    }

    escada ? (cout << "S") : (cout << "N");
    cout << endl;

    return 0;
}