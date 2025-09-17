#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define MAX 100

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


bool possivel(int num)
{
    if (num < 0)
        return false;
    int i, j;
    for (i = 0; i*i <= num; i++)
    {
        int resto = num - (i*i);
        int raiz = (int)sqrt(resto);
        if (raiz * raiz == resto) return true;
    }
    return false;
}

int main()
{
    _ 
    int num;
    while (cin >> num)
    {
        possivel(num) ? (cout << "YES" << endl) : (cout << "NO" << endl);
    }
    return 0;
}