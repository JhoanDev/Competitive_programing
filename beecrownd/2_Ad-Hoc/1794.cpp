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
    int N, LA, LB, SA, SB;
    cin >> N;
    cin >> LA >> LB;
    cin >> SA >> SB;
    if (N >= LA && N <= LB && N >= SA && N <= SB) cout << "possivel" << endl;
    else cout << "impossivel" << endl;
    return 0;
}