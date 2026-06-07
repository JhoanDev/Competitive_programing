#include <bits/stdc++.h>
#include <iterator>
#include <set>
#include <utility>
#include <vector>

using namespace std;
#define endl '\n'
#define f first
#define s second

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

#define tam 5

bool valido(const vector<vector<char>>& mat, int x, int y, const set<pair<int, int>>& visitados)
{
    if (x < 0 || x >= tam || y < 0 || y >= tam || visitados.count({x, y}) || mat[x][y] == '1')
    {
        return false;
    }
    return true;
}

bool percorre(vector<vector<char>>& matriz, int i, int j, set<pair<int, int>>& visitados)
{
    visitados.insert({i, j});
    if (i == tam - 1 && j == tam - 1)
    {
        visitados.erase({i, j});
        return true;
    }
    if (valido(matriz, i + 1, j, visitados))
    {
        if (percorre(matriz, i + 1, j, visitados))
        {
            return true;
        }
    }
    if (valido(matriz, i, j + 1, visitados))
    {
        if (percorre(matriz, i, j + 1, visitados))
        {
            return true;
        }
    }
    if (valido(matriz, i - 1, j, visitados))
    {
        if (percorre(matriz, i - 1, j, visitados))
        {
            return true;
        }
    }
    if (valido(matriz, i, j - 1, visitados))
    {
        if (percorre(matriz, i, j - 1, visitados))
        {
            return true;
        }
    }
    visitados.erase({i, j});
    return false;
}

int main()
{
    //_
    int t, i, j;
    cin >> t;
    vector<vector<char>> matriz(tam, vector<char>(tam));

    for (int k = 0; k < t; k++)
    {
        for (i = 0; i < tam; i++)
        {
            for (j = 0; j < tam; j++)
            {
                cin >> matriz[i][j];
            }
        }
        if (matriz[0][0] == '1')
        {
            cout << "ladrao" << endl;
            continue;
        }
        set<pair<int, int>> visitados;

        bool ganharam = percorre(matriz, 0, 0, visitados);

        if (ganharam)
            cout << "policia";
        else
            cout << "ladrao";
        cout << endl;
    }

    return 0;
}