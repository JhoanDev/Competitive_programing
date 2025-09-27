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

struct Ponto
{
    int x;
    int y;
};

int main()
{
    _ int testes;
    cin >> testes;
    Ponto A, B, C, D, R;
    for (int i = 0; i < testes; i++)
    {
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y >> R.x >> R.y;
        bool esta = false;

        if (R.x >= A.x && R.x <= B.x && R.y >= A.y && R.y <= D.y)
                esta = true;

        (esta) ? (cout << "1" << endl) : (cout << "0" << endl);
    }
    return 0;
}