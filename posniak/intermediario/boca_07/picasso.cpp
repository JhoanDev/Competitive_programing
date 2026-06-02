#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <set>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;
#define endl '\n'
#define f first
#define s second

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

void imprimir_matriz(const vector<vector<char>>& mat)
{
    for (const auto& linha : mat)
    {
        for (char c : linha)
        {
            cout << c;
        }
        cout << '\n';
    }
}

bool valido(const vector<vector<char>>& mat, int x, int y, int tam)
{
    if (x < 0 || x >= tam || y < 0 || y >= tam)
    {
        return false;
    }
    return true;
}

void trocar_em_triangulo(vector<vector<char>>& mat, int tam, set<pair<int, int>>& visitados, int linha, int coluna)
{
    int i, j_atual, tam_atual = 1, var_atual = 1, tam_sobrando = 1, iteração = 0, j_inicial;
    for (i = linha; i < tam; i++)
    {
        j_inicial = coluna - iteração;
        tam_atual = 1 + (iteração++) * 2;
        tam_sobrando = tam_atual;
        var_atual = iteração;
        for (int k = 0; k < tam_atual; k++)
        {
            j_atual = j_inicial + k;
            if (!valido(mat, i, j_atual, tam) || mat[i][j_atual] != '*' || visitados.count({i, j_atual}))
            {
                return;
            }
            else
            {
                string num = to_string(var_atual);
                for (char& d : num)
                {
                    if (!tam_sobrando-- || !valido(mat, i, j_atual, tam) || mat[i][j_atual] != '*' || visitados.count({i, j_atual}))
                    {
                        continue;
                    }
                    mat[i][j_atual] = d;
                    visitados.insert({i, j_atual});
                    k++;
                    j_atual = j_inicial + k;
                }
                k--;
            }
        }
    }
}

void reescrever(vector<vector<char>>& mat, int tam)

{
    int i, j;
    set<pair<int, int>> visitados;
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            if (mat[i][j] == '*' && !visitados.count({i, j}))
            {
                trocar_em_triangulo(mat, tam, visitados, i, j);
            }
            else
            {
                visitados.insert({i, j});
            }
        }
    }
}

int main()
{
    int tam, i;
    string aux;
    cin >> tam;

    vector<vector<char>> mat(tam);
    for (i = 0; i < tam; i++)
    {
        cin >> aux;
        mat[i] = vector<char>(aux.begin(), aux.end());
    }

    reescrever(mat, tam);
    imprimir_matriz(mat);

    return 0;
}