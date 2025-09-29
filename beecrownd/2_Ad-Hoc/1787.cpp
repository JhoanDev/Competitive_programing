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

bool e_potencia_de_2(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

int main()
{
    _ int rodadas, i;

    while (cin >> rodadas)
    {
        int rita = 0, uilton = 0, ingred = 0;
        int r, u, in;
        if (rodadas == 0)
            break;
        for (i = 0; i < rodadas; i++)
        {
            int max = -1;
            cin >> u >> r >> in;
            if (e_potencia_de_2(r))
            {
                rita++;
            }
            if (e_potencia_de_2(u))
            {
                uilton++;
            }
            if (e_potencia_de_2(in))
            {
                ingred++;
            }

            if (u > max)
                max = u;
            if (in > max)
                max = in;
            if (r > max)
                max = r;

            if (max == in && e_potencia_de_2 (in))
                ingred++;
            if (max == u && e_potencia_de_2 (u))
                uilton++;
            if (max == r && e_potencia_de_2 (r))
                rita++;
        }

        if (ingred > uilton && ingred > rita)
            cout << "Ingred" << endl;
        else if (uilton > ingred && uilton > rita)
            cout << "Uilton" << endl;
        else if (rita > uilton && rita > ingred)
            cout << "Rita" << endl;
        else
            cout << "URI" << endl;
    }

    return 0;
}