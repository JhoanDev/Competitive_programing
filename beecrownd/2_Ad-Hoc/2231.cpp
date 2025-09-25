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
    int qnt_temperaturas, intervalo, i, aux, testes = 1;
    while (true)
    {
        cin >> qnt_temperaturas >> intervalo;
        if (qnt_temperaturas == 0 && intervalo == 0)
            break;
        cout << "Teste " << testes++ << endl;
        int maior = -INF, menor = INF, valor_atual = 0, media;
        vector<int> temperaturas;
        temperaturas.reserve(qnt_temperaturas);
        for (i = 0; i < qnt_temperaturas; i++)
        {
            cin >> aux;
            temperaturas.push_back(aux);
        }

        for (i = 0; i < intervalo; i++)
        {
            valor_atual += temperaturas.at(i);
        }
        media = valor_atual / intervalo;
        if (media > maior)
            maior = media;
        if (media < menor)
            menor = media;

        for (i = intervalo; i < qnt_temperaturas; i++)
        {
            valor_atual -= temperaturas.at(i - intervalo);
            valor_atual += temperaturas.at(i);

            media = valor_atual / intervalo;
            if (media > maior)
                maior = media;
            if (media < menor)
                menor = media;
        }
        cout << menor << " " << maior << endl << endl;
    }

    return 0;
}