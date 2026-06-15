#include <bits/stdc++.h>

using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define endl '\n'

using ll = long long;

int main()
{
    fastio;
    ll n, i;
    while (cin >> n && n != 0)
    {
        cout << 1;
        i = 2;
        while (i * i <= n)
        {
            cout << " " << i * i;
            i++;
        }
        cout << endl;
    }
    return 0;
}