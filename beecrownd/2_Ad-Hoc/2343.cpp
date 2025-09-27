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
    _ int n, a, b;
    pair<int, int> par;
    int caiu = 0;
    cin >> n;
    map<pair<int, int>, int> mapa;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a >> b;
        par = make_pair(a, b);
        if (mapa.count(par) != 0)
            caiu = 1;
        else
            mapa[par] = 1;
    }
    cout << caiu << endl;

    return 0;
}