#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ssize(x)
#define endl '\n'
const int MAXN = 10000000;

bool primo(int num)
{

    if (num == 1)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;

    for (ll n = 3; n * n <= num; n += 2)
    {
        if (num % n == 0)
        {
            return false;
        }
    }
    return true;
}

void solve(vi& primos)
{
    for (int i = 1; i <= MAXN; i++)
    {
        if (primo(i))
        {
            primos.push_back(i);
        }
    }
}

void primos_gemeos(const vi& primos, vi& gemeos)
{
    int fim = primos.size();
    set<int> res;
    for (int j = 0; j < fim - 1; j++)
    {
        if (primos[j + 1] - primos[j] == 2)
        {
            res.insert(primos[j + 1]);
            res.insert(primos[j]);
        }
    }
    for (auto& a : res)
    {
        gemeos.push_back(a);
    }
}

int main()
{
    fastio;
    vi primos;
    solve(primos);
    int consultas;
    cin >> consultas;
    vi gemeos;
    primos_gemeos(primos, gemeos);
    vi prefixos(MAXN + 1, 0);
    for (auto& g : gemeos)
        prefixos[g] = 1;
    for (int i = 1; i < 1000001; i++)
        prefixos[i] += prefixos[i - 1];

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