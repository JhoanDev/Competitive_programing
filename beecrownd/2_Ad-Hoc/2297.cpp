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
    _ int teste = 1, rodadas, aux1, aux2, i;
    while (true)
    {
        cin >> rodadas;
        if (rodadas == 0)
            break;
        cout << "Teste " << teste++ << endl;
        int a = 0, b = 0;
        for (i = 0; i < rodadas; i++)
        {
            cin >> aux1 >> aux2;
            a += aux1;
            b += aux2;
        }
        (a > b) ? (cout << "Aldo" << endl) : (cout << "Beto" << endl);
        cout << endl;
    }

    return 0;
}