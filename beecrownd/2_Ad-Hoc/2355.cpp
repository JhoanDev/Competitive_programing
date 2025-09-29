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
    int min;
    const double taxa_a = 7.0 / 90.0;
    const double taxa_b = 1.0 / 90.0;

    int a;
    int b;

    while (cin >> min)
    {
        if (min == 0)
            break;

        b = min * taxa_b;
        a = ceil(min * taxa_a);
        cout << "Brasil " << b << " x Alemanha " << a << endl;
    }

    return 0;
}