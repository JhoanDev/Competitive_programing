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
    int qnt, nota, i, chave_maior = 0, qnt_maior = 0;
    cin >> qnt;
    map<int, int> notas;
    for (i = 0; i < qnt; i++)
    {
        cin >> nota;
        if (notas.count(nota))
            notas[nota]++;
        else
            notas[nota] = 1;
    }

    for (auto it = notas.rbegin(); it != notas.rend(); ++it)
    {
        if (it->s > qnt_maior)
        {
            chave_maior = it->f;
            qnt_maior = it->s;
        }
    }
    cout << chave_maior << endl;

    return 0;
}