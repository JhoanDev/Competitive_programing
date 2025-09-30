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
    _ int n, m, aux, i, j;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        map<int, int> colocacoes;
        int maior = -INF, segundo_maior = -INF;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> aux;
                if (colocacoes.count(aux) != 0)
                    colocacoes[aux]++;
                else
                {
                    colocacoes[aux] = 1;
                }
            }
        }

        for (auto &par : colocacoes)
        {
            if (par.s > maior)
            {
                segundo_maior = maior;
                maior = par.s;
            }
            else if (par.s > segundo_maior)
            {
                segundo_maior = par.s;
            }
        }

        for (auto &par : colocacoes)
        {
            if (par.s == segundo_maior || segundo_maior == -INF)
                cout << par.f << " ";
        }
        cout << endl;
    }

    return 0;
}