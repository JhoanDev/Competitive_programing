// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
constexpr int INF = 0x3f3f3f3f;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

struct Caixa
{
    int tempo_ate_terminar;
    int id;
    int tempo_por_item;

    bool operator<(Caixa const& outro) const
    {
        if (outro.tempo_ate_terminar == tempo_ate_terminar)
            return id > outro.id;
        return tempo_ate_terminar > outro.tempo_ate_terminar;
    }
};

int main()
{
    fastio;
    int num_f, num_c, aux, tempo_total = -INF;
    cin >> num_f >> num_c;
    priority_queue<Caixa> caixas;
    for (int i = 1; i <= num_f; ++i)
    {
        Caixa c = {0, i, 0};
        cin >> c.tempo_por_item;
        caixas.push(c);
    }

    queue<int> clientes;
    for (size_t i = 0; i < num_c; ++i)
    {
        cin >> aux;
        clientes.push(aux);
    }

    while (!clientes.empty())
    {
        Caixa c = caixas.top();
        caixas.pop();
        c.tempo_ate_terminar += clientes.front() * c.tempo_por_item;
        caixas.push(c);
        clientes.pop();
    }
    while (!caixas.empty())
    {
        if (caixas.top().tempo_ate_terminar > tempo_total)
            tempo_total = caixas.top().tempo_ate_terminar;
        caixas.pop();
    }

    cout << tempo_total << endl;
    return 0;
}

// [13,10]