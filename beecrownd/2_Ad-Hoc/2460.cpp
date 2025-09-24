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
    _
    int pessoas, saem, i, aux;
    cin >> pessoas;
    vector<int> fila;
    fila.reserve(pessoas);

    for (i = 0; i < pessoas; i++)
    {
        cin >> aux;
        fila.push_back(aux);
    }

    cin >> saem;
    for (i = 0; i < saem; i++)
    {
        cin >> aux;
        auto it = find(fila.begin(), fila.end(), aux);
        fila.erase(it);
    }

    for (i = 0; i < fila.size() - 1; i++)
    {
        cout << fila.at(i) << " ";
    }
    cout << fila.at(fila.size() - 1) << endl;

    return 0;
}