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
    _ int t, i, n;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cin >> n;
        (n % 2 == 0) ? (cout << "1") : (cout << "9");
        cout << endl;
    }

    return 0;
}