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

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ssize(x)
#define endl '\n'

ll solve(int num)
{
    int ant = 0, atual = 1, res, i;
    for (i = 0; i < num; i++)
    {
        res = ant + atual;
        ant = atual;
        atual = res;
    }
    return res;
}

int main()
{
    fastio;
    int n;
    while (cin >> n && n != 0)
    {
        cout << solve(n) << endl;
    }

    return 0;
}