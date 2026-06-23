#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

bool possivel(ll target, const vector<pair<bool, ll>>& celulas, const int k)
{
    int seq = 0;
    bool obrigatorio = false;
    for (size_t i = 0; i < celulas.size(); ++i)
    {

        if (celulas[i].first)
        {
            if (celulas[i].second > target)
            {
                obrigatorio = true;
            }
        }
        else
        {
            if (celulas[i].second > target)
            {
                if (obrigatorio)
                    seq++;
                obrigatorio = false;
            }
        }
    }
    if (obrigatorio)
        seq++;

    return seq <= k;
}

int main()
{
    fastio;
    size_t casos;
    cin >> casos;
    for (size_t c = 0; c < casos; ++c)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<bool, ll>> celulas(n); // azul true, vemelhor false
        ll aux;
        ll max = -LINF;
        string cores;
        cin >> cores;
        for (size_t i = 0; i < n; ++i)
        {
            cin >> aux;
            celulas[i].first = (cores.at(i) == 'B') ? true : false;
            celulas[i].second = aux;
            if (aux > max)
                max = aux;
        }

        ll l, u, m;
        l = 0;
        u = (max + 1);

        while (l < u)
        {
            m = l + (u - l) / 2;
            if (possivel(m, celulas, k))
                u = m;
            else
                l = m + 1;
        }

        cout << l << endl;
    }

    return 0;
}