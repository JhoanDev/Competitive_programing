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
    _
    int testes, i, j, k, quantidade_grupos, numero, pos, valor_prox, aux;
    cin >> testes;
    for (i = 0; i < testes; i++)
    {
        valor_prox = INF;
        cin >> quantidade_grupos >> numero;
        for (j = 0; j < quantidade_grupos; j++)
        {
            cin >> aux;
            aux = abs(aux - numero);
            if (aux < valor_prox)
            {
                valor_prox = aux;
                pos = j;
            }
        }
        cout << (pos + 1) << endl;
    }

    return 0;
}