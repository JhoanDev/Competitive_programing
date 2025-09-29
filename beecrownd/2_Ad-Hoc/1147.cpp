#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define TAM 8

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct cord
{
    int x;
    int y;
};

cord retorna_posicao(string pos)
{
    cord aux;
    aux.y = pos[0] - '0' - 1;
    aux.x = pos[1] - '0' - 49;
    return aux;
}

int posicao_valida(cord pos, vector<vector<int>> &tab)
{
    int x, y;
    if (pos.x < 0 || pos.x >= TAM || pos.y < 0 || pos.y >= TAM)
    {
        return 0;
    }

    y = pos.y + 1;
    x = pos.x + 1;

    if (x >= 0 && x < TAM && y >= 0 && y < TAM)
    {
        if (tab[x][y] == 1)
            return 0;
    }
    x = pos.x - 1;

    if (x >= 0 && x < TAM && y >= 0 && y < TAM)
    {
        if (tab[x][y] == 1)
            return 0;
    }

    return 1;
}

int main()
{
    _ int caso = 1, i, possiveis;
    cord cavalo, pos;
    string aux;
    while (true)
    {
        possiveis = 0;
        vector<vector<int>> tab(TAM, vector<int>(TAM));
        cin >> aux;
        if (aux == "0")
            break;
        cavalo = retorna_posicao(aux);
        for (i = 0; i < 8; i++)
        {
            cin >> aux;
            pos = retorna_posicao(aux);
            tab[pos.x][pos.y] = 1;
        }

        pos.x = cavalo.x - 2;
        pos.y = cavalo.y + 1;
        possiveis += posicao_valida(pos, tab);
        pos.y = cavalo.y - 1;
        possiveis += posicao_valida(pos, tab);

        pos.x = cavalo.x + 2;
        pos.y = cavalo.y + 1;
        possiveis += posicao_valida(pos, tab);
        pos.y = cavalo.y - 1;
        possiveis += posicao_valida(pos, tab);

        pos.x = cavalo.x + 1;
        pos.y = cavalo.y + 2;
        possiveis += posicao_valida(pos, tab);
        pos.x = cavalo.x - 1;
        possiveis += posicao_valida(pos, tab);

        pos.x = cavalo.x + 1;
        pos.y = cavalo.y - 2;
        possiveis += posicao_valida(pos, tab);
        pos.x = cavalo.x - 1;
        possiveis += posicao_valida(pos, tab);

        cout << "Caso de Teste #" << caso++ << ": " << possiveis << " movimento(s)." << endl;
    }

    return 0;
}