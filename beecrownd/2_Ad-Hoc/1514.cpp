#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int ninguem_resolveu_todos(vector<vector<int>> &matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        bool flag = false;
        for (int j = 0; j < colunas; j++)
        {
            if (matriz[i][j] == 0)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return 0;
    }
    return 1;
}

int todo_problema_foi_resolvido(vector<vector<int>> &matriz, int linhas, int colunas)
{
    for (int j = 0; j < colunas; j++)
    {
        bool flag = false;
        for (int i = 0; i < linhas; i++)
        {
            if (matriz[i][j] == 1)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return 0;
    }
    return 1;
}

int nao_ha_nenhum_resolvido_por_todos(vector<vector<int>> &matriz, int linhas, int colunas)
{
    for (int j = 0; j < colunas; j++)
    {
        bool flag = false;
        for (int i = 0; i < linhas; i++)
        {
            if (matriz[i][j] == 0)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return 0;
    }
    return 1;
}

int todos_resolveram_ao_menos_um(vector<vector<int>> &matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        bool flag = false;
        for (int j = 0; j < colunas; j++)
        {
            if (matriz[i][j] == 1)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return 0;
    }
    return 1;
}

int main()
{
    _ int participantes, problemas;
    while (cin >> participantes >> problemas)
    {
        if (problemas == 0 && participantes == 0)
            break;

        vector<vector<int>> matriz(participantes, vector<int>(problemas));
        for (int i = 0; i < participantes; i++)
        {
            for (int j = 0; j < problemas; j++)
            {
                cin >> matriz[i][j];
            }
        }

        int c1 = ninguem_resolveu_todos(matriz, participantes, problemas);
        int c2 = todos_resolveram_ao_menos_um(matriz, participantes, problemas);
        int c3 = nao_ha_nenhum_resolvido_por_todos(matriz, participantes, problemas);
        int c4 = todo_problema_foi_resolvido(matriz, participantes, problemas);

        cout << (c1 + c2 + c3 + c4) << endl;
    }

    return 0;
}
