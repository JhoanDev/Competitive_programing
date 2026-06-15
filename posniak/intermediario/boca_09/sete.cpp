#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

int main()
{
    fastio;
    int instances;
    cin >> instances;
    while (instances--)
    {
        ll indice;
        cin >> indice;
        if (indice % 4 == 0)
            cout << '1';
        else if (indice % 4 == 1)
            cout << '7';
        else if (indice % 4 == 2)
            cout << '9';
        else if (indice % 4 == 3)
            cout << '3';
        cout << endl;
    }
    return 0;
}
