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
    int n, ant, atual, i;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        bool ordenado = false;
        int cont = 0;
        while (!ordenado)
        {
            cont++;
            ordenado = true;
            ant = 0;
            for (i = 0; i < n; i++)
            {
                cin >> atual;
                if (atual < ant)
                    ordenado = false;
                ant = atual;
            }
        }
        cout << cont << endl;
    }

    return 0;
}