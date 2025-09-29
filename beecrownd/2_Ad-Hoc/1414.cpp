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
    _ int times, partidas, pontos, i, aux;
    string entrada;
    while (cin >> times >> partidas)
    {
        if (times == 0)
            break;
        pontos = 0;
        for (i = 0; i < times; i++)
        {
            cin >> entrada >> aux;
            pontos += aux;
        }
        cout << (partidas * 3) - pontos << endl;
    }
    return 0;
}