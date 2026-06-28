// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ssize(x)
#define endl '\n'

int main()
{
    fastio;
    int chocolates, consultas;
    cin >> chocolates >> consultas;
    vector<ull> precos;
    precos.reserve(chocolates);
    for (size_t i = 0; i < chocolates; ++i)
    {
        ull p;
        cin >> p;
        precos.push_back(p);
    }
    ull limite, comprar;
    for (size_t i = 0; i < consultas; ++i)
    {
        cin >> limite >> comprar;
    }

    return 0;
}