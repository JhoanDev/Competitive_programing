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
    int ataque, defesa, i, aux;
    while (true)
    {
        bool impedido = true;
        cin >> ataque >> defesa;
        if (ataque == 0 && defesa == 0)
            break;
        vector<int> atacantes;
        atacantes.reserve(ataque);
        vector<int> defensores;
        defensores.reserve(defesa);
        for (i = 0; i < ataque; i++)
        {
            cin >> aux;
            atacantes.push_back(aux);
        }
        for (i = 0; i < defesa; i++)
        {
            cin >> aux;
            defensores.push_back(aux);
        }

        sort(atacantes.begin(), atacantes.end());
        sort(defensores.begin(), defensores.end());

        if (atacantes.at(0) >= defensores.at(1))
            impedido = false;

        impedido ? (cout << "Y" << endl) : (cout << "N" << endl);
    }

    return 0;
}