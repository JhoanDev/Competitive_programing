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

    string entrada;
    int i;
    while (cin >> entrada)
    {
        vector<int> digitos(11);
        for (i = 0; i < 9; i++)
        {
            digitos[i] = entrada[i] - '0';
        }
        for (i = 1; i <= 9; i++)
        {
            digitos[9] += digitos[i - 1] * i;
            digitos[10] += digitos[i - 1] * (10 - i);
        }
        digitos[9] %= 11;
        digitos[10] %= 11;
        if (digitos[9] == 10)
            digitos[9] = 0;
        if (digitos[10] == 10)
            digitos[10] = 0;

        cout << digitos[0] << digitos[1] << digitos[2] << '.'
             << digitos[3] << digitos[4] << digitos[5] << '.'
             << digitos[6] << digitos[7] << digitos[8] << '-'
             << digitos[9] << digitos[10] << endl;
    }

    return 0;
}