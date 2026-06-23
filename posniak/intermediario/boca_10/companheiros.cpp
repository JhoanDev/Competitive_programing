#include <bits/stdc++.h>

using namespace std;

struct Soldado
{
    bool vivo;
    int esquerda;
    int direita;
};

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

int main()
{
    fastio;
    int soldados, relatorios;
    while ((cin >> soldados >> relatorios) && (soldados != 0 || relatorios != 0))
    {
        vector<Soldado> linha_frente((soldados + 2));
        for (int i = 1; i <= soldados; ++i)
            linha_frente[i] = {true, ((i != 1) ? (i - 1) : (0)), ((i != soldados) ? (i + 1) : (soldados + 1))};

        linha_frente[0].vivo = false;
        linha_frente[0].esquerda = -1;
        linha_frente[0].direita = 1;

        linha_frente[soldados + 1].vivo = false;
        linha_frente[soldados + 1].esquerda = soldados;
        linha_frente[soldados + 1].direita = -1;

        for (int i = 0; i < relatorios; ++i)
        {
            int l, r;
            cin >> l >> r;

            linha_frente[l].vivo = false;
            linha_frente[l].direita = r + 1;

            linha_frente[r].vivo = false;
            linha_frente[r].esquerda = l - 1;

            int vivo_esq = 0, vivo_dir = 0, prox;

            prox = l - 1;

            unordered_set<int> passados_left;
            do
            {
                passados_left.insert(prox);
                prox = linha_frente[prox].direita;
                if (prox == 0 || prox == soldados + 1)
                    break;
                if (linha_frente[prox].vivo)
                    vivo_esq = prox;
            } while (!vivo_esq);

            for (auto p : passados_left)
            {
                linha_frente[p].direita = vivo_esq;
            }

            prox = r + 1;

            unordered_set<int> passados_right;
            do
            {
                passados_right.insert(prox);
                prox = linha_frente[prox].esquerda;
                if (prox == 0 || prox == soldados + 1)
                    break;
                if (linha_frente[prox].vivo)
                    vivo_dir = prox;
            } while (!vivo_dir);

            for (auto p : passados_right)
            {
                linha_frente[p].esquerda = vivo_dir;
            }

            if (vivo_dir > 0 && vivo_dir < (soldados + 1))
                cout << vivo_dir;
            else
                cout << '*';

            cout << ' ';

            if (vivo_esq > 0 && vivo_esq < (soldados + 1))
                cout << vivo_esq;
            else
                cout << '*';

            cout << endl;
        }
        cout << '-' << endl;
    }
    return 0;
}
