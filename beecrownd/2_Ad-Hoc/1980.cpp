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
    string entrada;
    vector<llu> fat(16);
    int i;
    fat[0] = 1;
    for (i = 1; i < 16; i++)
    {
        fat[i] = fat[i - 1] * i;
    }

    while (cin >> entrada)
    {
        if (entrada == "0")
            break;

        cout << fat[entrada.length()] << endl;
    }

    return 0;
}