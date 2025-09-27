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
    _ int n, aux;
    set<int> alunos;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> aux;
        alunos.insert(aux);
    }
    cout << alunos.size() << endl;

    return 0;
}