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
    int a, b, c;
    int h, l;

    cin >> a >> b >> c;
    cin >> h >> l;

    vector<int> colchao = {a, b, c};
    vector<int> porta = {h, l};

    sort(colchao.begin(), colchao.end());
    sort(porta.begin(), porta.end());

    (porta[1] >= colchao[1] && porta[0] >= colchao[0]) ? (cout << "S" << endl) : (cout << "N" << endl);

    return 0;
}