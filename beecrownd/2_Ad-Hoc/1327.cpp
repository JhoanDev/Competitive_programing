#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define CARDS 52
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    _ int qnt_players, i, card;
    string nome;
    while (true)
    {
        cin >> qnt_players;
        if (qnt_players == 0)
            break;
        vector<string> players(qnt_players);
        for (i = 0; i < qnt_players; i++)
        {
            cin >> players[i];
        }
        vector<int> cartas(CARDS);
        for (i = 0; i < CARDS; i++)
        {
            cin >> cartas[i];
        }
        int k = 0;
        while (true)
        {
            qnt_players = players.size();
            if (k + qnt_players > CARDS)
                break;
            pair<int, vector<int>> minimo(14, {});
            for (i = 0; i < qnt_players; i++)
            {
                card = cartas[k++];
                if (card < minimo.first)
                {
                    minimo.first = card;
                    minimo.second.clear();
                    minimo.second.push_back(i);
                }
                else if (card == minimo.first)
                    minimo.second.push_back(i);
            }
            if (qnt_players == ((int)minimo.second.size()))
            {
                break;
            }
            for (int j = (int)minimo.second.size() - 1; j >= 0; j--)
            {
                players.erase(players.begin() + minimo.second[j]);
            }
        }

        for (i = 0; i < ((int)players.size()); i++)
        {

            if (i != (int)players.size() - 1)
                cout << players[i] << " ";
            else
            {
                cout << players[i] << " " << endl;
            }
        }
    }

    return 0;
}
