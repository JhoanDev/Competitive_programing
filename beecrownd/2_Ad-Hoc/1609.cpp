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
    int testes, i, j, aux, qnt;
    cin >> testes;
    for (i = 0; i < testes; i++)
    {
        set<int> carneiros;
        cin >> qnt;
        for (j = 0; j < qnt; j++)
        {
            cin >> aux;
            carneiros.insert(aux);
        }
        cout << carneiros.size() << endl;
    }

    return 0;
}