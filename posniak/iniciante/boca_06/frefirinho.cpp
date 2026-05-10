#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

int main()
{
    //_
    int qnt_andares, pecas_andar, jogadores;
    cin >> qnt_andares >> pecas_andar >> jogadores;
    vector<int> andares(qnt_andares, pecas_andar);
    int jog_atual = 0;
    int jogada = 0;
    bool acabou = false;

    while (cin >> jogada)
    {
        if (!acabou)
        {
            if ((andares[jogada - 1] == 2 && andares[jogada] == 1) || andares[jogada - 1] == 1)
            {
                acabou = true;
            }
            else
            {
                andares[jogada - 1]--;
                jog_atual = (jog_atual + 1) % jogadores;
            }
        }
    }

    if (acabou)
    {
        cout << jog_atual + 1 << '\n';
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}