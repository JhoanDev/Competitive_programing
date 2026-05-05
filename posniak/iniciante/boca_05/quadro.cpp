#include <bits/stdc++.h>
#include <iterator>

using namespace std;

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

bool primo(ll num)
{
    if (!(num & 1))
        return false;
    ll i, raiz = sqrt(num);
    for (i = 3; i <= raiz; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    //_
    vector<ll> seq(101);
    seq[0] = 0;
    seq[1] = 1;
    seq[2] = 1;
    seq[3] = 2;

    bool soma = true;

    for (ll i = 4; i < 101; i++)
    {
        if (soma)
        {
            seq[i] = seq[i - 1] + seq[i - 2];
            soma = !primo(seq[i]);
        }
        else
        {
            seq[i] = seq[i - 1] - seq[i - 2];
            soma = true;
        }
    }

    ll n = 0;
    cin >> n;

    auto localizado = find(seq.begin(), seq.end(), n);
    if (localizado == seq.end())
    {
        cout << "Oxe" << endl;
    }
    else
    {
        int indice = distance(seq.begin(), localizado) + 1;
        cout << indice << endl;
    }
    return 0;
}