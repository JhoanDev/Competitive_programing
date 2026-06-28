// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int INF = 0x3f3f3f3f;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ssize(x)
#define endl '\n'

struct Comand
{
    int pos_inicial;
    int ultima_vez_teclado = -1;
};

int main()
{
    fastio;
    int qnt;
    while ((cin >> qnt) && (qnt != 0))
    {
        queue<int> comandos;
        int comando;
        int maior = -INF;
        unordered_map<int, Comand> historico;

        for (size_t i = 0; i < qnt; ++i)
        {
            cin >> comando;
            if (comando > maior)
                maior = comando;
            comandos.push(comando);
            historico[comando] = {comando, -1};
        }

        ll pressao = 0;
        int aux = 0;
        int comandos_dados = 0;
        while (!comandos.empty())
        {
            comando = comandos.front();
            if (historico[comando].ultima_vez_teclado == -1)
                pressao += historico[comando].pos_inicial + comandos_dados;
            else
                pressao += comandos_dados - historico[comando].ultima_vez_teclado;
            pressao += aux;
            comandos.pop();
            historico[comando].ultima_vez_teclado = comandos_dados;
            comandos_dados++;
        }
        cout << pressao << endl;
    }
    return 0;
}
