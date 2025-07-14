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
    _ int q, aux, s = 0, n = 0, i;
    cin >> q;
    for (i = 0; i < q; i++)
    {
        cin >> aux;
        if (aux)
            n++;
        else
            s++;
    }
    cout << ((n < s) ? "Y" : "N") << endl;

    return 0;
}