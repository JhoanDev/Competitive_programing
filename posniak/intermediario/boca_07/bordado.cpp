#include <bits/stdc++.h>
#include <format>
#include <iterator>

using namespace std;
#define endl '\n'
#define f first
#define s second

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

#define ponto '@'
#define vazio '.'

bool valido(int x, int y, int tam)
{
    if (x < 0 || x >= tam || y < 0 || y >= tam)
        return false;
    return true;
}

bool verifica_zero(const vector<vector<char>>& mat, int& x, int& y, int tam, vector<pair<int, int>>& borda)
{
    int j, i;
    int linha = x, coluna = y;
    int largura = 0, altura = 0;
    bool invalido = false;
    for (j = coluna; j < tam; j++)
    {
        if (mat[linha][j] == ponto)
        {
            borda.push_back(make_pair(linha, j));
            largura++;
            if (j != coluna)
            {
                if (valido(linha - 1, j, tam) && mat[linha - 1][j] == ponto)
                    invalido = true;

                if (valido(linha + 1, j, tam) && mat[linha + 1][j] == ponto && valido(linha, j + 1, tam) && mat[linha][j + 1] == ponto)
                    invalido = true;
            }
            else
            {
                if (valido(linha, j - 1, tam) && mat[linha][j - 1] == ponto)
                    invalido = true;
                if (valido(linha - 1, j, tam) && mat[linha - 1][j] == ponto)
                    invalido = true;
            }
        }
        else
            break;
    }

    j--;
    y = j;
    coluna = j;

    if (largura < 3 || invalido)
        return false;

    for (i = linha; i < tam; i++)
    {
        if (mat[i][coluna] == ponto)
        {
            borda.push_back(make_pair(i, coluna));
            altura++;
            if (i != linha)
            {
                if (valido(i, coluna - 1, tam) && mat[i][coluna - 1] == ponto && valido(i + 1, coluna, tam) && mat[i + 1][coluna] == ponto)
                    invalido = true;

                if (valido(i, coluna + 1, tam) && mat[i][coluna + 1] == ponto)
                    invalido = true;
            }
            else
            {
                if (valido(linha, j + 1, tam) && mat[linha][j + 1] == ponto)
                    invalido = true;
                if (valido(linha - 1, j, tam) && mat[linha - 1][j] == ponto)
                    invalido = true;
            }
        }
        else
        {

            break;
        }
    }
    i--;
    linha = i;
    if (altura < 3 || invalido)
        return false;

    for (j = coluna; j >= 0; j--)
    {
        if (mat[linha][j] == ponto)
        {
            borda.push_back(make_pair(linha, j));
            largura--;
            if (j != coluna)
            {
                if (valido(linha - 1, j, tam) && mat[linha - 1][j] == ponto && valido(linha, j - 1, tam) && mat[linha][j - 1] == ponto)
                    invalido = true;

                if (valido(linha + 1, j, tam) && mat[linha + 1][j] == ponto)
                    invalido = true;
            }
            else
            {
                if (valido(linha, j + 1, tam) && mat[linha][j + 1] == ponto)
                    invalido = true;
                if (valido(linha + 1, j, tam) && mat[linha + 1][j] == ponto)
                    invalido = true;
            }
        }

        else
            break;
    }
    j++;
    coluna = j;

    if (largura != 0 || invalido)
        return false;

    for (i = linha; i >= 0; i--)
    {
        if (mat[i][coluna] == ponto)
        {
            borda.push_back(make_pair(i, coluna));
            altura--;
            if (i != linha)
            {
                if (valido(i, coluna - 1, tam) && mat[i][coluna - 1] == ponto)
                    invalido = true;

                if (valido(i, coluna + 1, tam) && mat[i][coluna + 1] == ponto && valido(i - 1, coluna, tam) && mat[i - 1][coluna] == ponto)
                    invalido = true;
            }

            else
            {
                if (valido(linha, j - 1, tam) && mat[linha][j - 1] == ponto)
                    invalido = true;
                if (valido(linha + 1, j, tam) && mat[linha + 1][j] == ponto)
                    invalido = true;
            }
        }
        else
            break;
    }

    if (altura != 0 || invalido)
    {
        return false;
    }

    return true;
}

int zeros(vector<vector<char>>& mat, int tam, bool& erro)
{
    int j, i;
    int zeros = 0;
    bool aux;
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            if (mat[i][j] == ponto)
            {
                vector<pair<int, int>> borda;
                aux = verifica_zero(mat, i, j, tam, borda);

                if (aux)
                {
                    for (auto& p : borda)
                    {
                        mat[p.first][p.second] = '.';
                    }
                    zeros++;
                }
                else
                    erro = true;
            }
        }
    }
    return zeros;
}

int main()
{
    //_
    int tam, i;
    string aux;
    cin >> tam;
    bool erro = false;
    vector<vector<char>> mat(tam);
    for (i = 0; i < tam; i++)
    {
        cin >> aux;
        mat[i] = vector<char>(aux.begin(), aux.end());
    }

    int res = zeros(mat, tam, erro);
    cout << res << endl;
    if (erro)
        cout << "ERRO\n";

    return 0;
}