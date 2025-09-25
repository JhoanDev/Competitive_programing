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
    _ int qnt_virus, i, aux;
    while (cin >> qnt_virus)
    {
        vector<int> virus;
        virus.reserve(qnt_virus);
        for (i = 0; i < qnt_virus; i++)
        {
            cin >> aux;
            virus.push_back(aux);
        }

        sort(virus.begin(), virus.end());

        int infecao = 0;

        for (i = 0; i < qnt_virus / 2; i++)
        {
            infecao += virus.at(qnt_virus - i - 1) - virus.at(i);
        }

        cout << infecao << endl;
    }

    return 0;
}