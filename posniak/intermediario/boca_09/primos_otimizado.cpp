#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

const int MAXN = 10000000;

void solve(vector<bool>& primos)
{
    primos[0] = false;
    primos[1] = false;
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (primos[i])
        {
            for (int j = i*i; j <= MAXN; j+=i)
            {
                primos[j] = false;
            }
        }
    }
}

void primos_gemeos_prefixo(vi& prefixos)
{

    vector<bool> primos(MAXN + 1, true);
    solve(primos);
    for (int j = 0; j < MAXN-2; j++)
    {
        if (primos[j] && primos[j+2]) {
            prefixos[j] = 1;
            prefixos[j+2] = 1;
        
        }
    }

    for (int i = 1; i < MAXN; i++)
        prefixos[i] += prefixos[i - 1];
}

int main()
{
    fastio;
    int consultas;
    cin >> consultas;
    vi prefixos(MAXN + 1, 0);
    primos_gemeos_prefixo(prefixos);
    for (int i = 1; i <= consultas; i++)
    {
        int a, b, res = 0;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        res = prefixos[b] - prefixos[a - 1];

        cout << res << endl;
    }
    return 0;
}