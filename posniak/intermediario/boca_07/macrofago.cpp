#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <type_traits>
#include <vector>

using namespace std;
#define endl '\n'
#define f first
#define s second

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

#define b 0
#define v 1
#define c 2
#define barreira 'm'

struct elementos
{
    int qnt;
    string nome;

    bool operator<(const elementos& outro) const
    {
        if (qnt != outro.qnt)
            return qnt > outro.qnt;
        return nome < outro.nome;
    }
};

bool valido(const vector<vector<char>>& mat, int x, int y, int tam)
{
    if (x < 0 || x >= tam || y < 0 || y >= tam || mat[x][y] == barreira)
    {
        return false;
    }
    return true;
}

void buscar(vector<vector<char>>& mat, int x, int y, vector<elementos>& ele, int tam)
{

    if (mat[x][y] != barreira)
    {
        char aux = mat[x][y];
        if (aux == 'b')
        {
            ele.at(b).qnt++;
        }
        else if (aux == 'v')
        {
            ele.at(v).qnt++;
        }
        else if (aux == 'c')
        {
            ele.at(c).qnt++;
        }
        mat[x][y] = barreira;
    }
    else

        return;

    if (valido(mat, x + 1, y, tam))
    {
        buscar(mat, x + 1, y, ele, tam);
    }
    if (valido(mat, x - 1, y, tam))
    {
        buscar(mat, x - 1, y, ele, tam);
    }
    if (valido(mat, x, y - 1, tam))
    {
        buscar(mat, x, y - 1, ele, tam);
    }
    if (valido(mat, x, y + 1, tam))
    {
        buscar(mat, x, y + 1, ele, tam);
    }

    return;
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

    vector<elementos> ele;
    ele.push_back({0, "BACTERIA"});
    ele.push_back({0, "VIRUS"});
    ele.push_back({0, "CANCER"});

    buscar(mat, 0, 0, ele, tam);

    sort(ele.begin(), ele.end());
    for (auto& e : ele)
    {
        cout << e.qnt << " " << e.nome << endl;
    }

    return 0;
}