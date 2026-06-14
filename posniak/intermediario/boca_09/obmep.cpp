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

// 1 = 3, 2 = 2, 3 = 1, 4 = 0

int index_ciclo_4(string num)
{

    int doisultimos = (num.size() >= 2) ? stoi(num.substr(num.size() - 2)) : num.at(num.size() - 1) - '0';
    int mod = doisultimos % 4;
    return mod;
}

int index_ciclo_2(string num)
{
    int ultimo = num.at(num.size() - 1) - '0';
    int mod = ultimo % 2;
    return mod;
}

int ciclo4base2[4] = {1, 2, 4, 3};
int ciclo4base3[4] = {1, 3, 4, 2};
int ciclo2base4[2] = {1, 4};

const int m = 5;

int main()
{
    fastio;
    string n;
    cin >> n;
    int v1, v2, v3, v4;
    v1 = 1;
    v2 = ciclo4base2[index_ciclo_4(n)];
    v3 = ciclo4base3[index_ciclo_4(n)];
    v4 = ciclo2base4[index_ciclo_2(n)];

    int res = ((v1 % m) + (v2 % m) + (v3 % m) + (v4 % m)) % m;
    cout << res << endl;
    return 0;
}
