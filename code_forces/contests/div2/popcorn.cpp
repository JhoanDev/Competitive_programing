#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

ll solve(ll val, ll max_qnt)
{
    ll resposta = 0;

    for (int i = 0; i <= 30; ++i)
    {
        ll valor_bit = 1LL << i;
        if (valor_bit > val)
            break;
        ll qtd = min(max_qnt, val / valor_bit);
        resposta += qtd;
        val -= qtd * valor_bit;
    }

    return resposta;
}

int main()
{
    fastio;
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}