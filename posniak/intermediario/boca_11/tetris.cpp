#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ssize(x)
#define endl '\n'

class Jogador
{
  public:
    size_t pontuacao = 0;
    string nome;

    Jogador(size_t p, string n)
    {
        nome = n;
        pontuacao = p;
    }

    bool operator<(const Jogador outro) const
    {
        if (pontuacao == outro.pontuacao)
            return nome < outro.nome;
        return pontuacao > outro.pontuacao;
    }
};

int main()
{
    fastio;
    int quantidade_jog, testes = 1;
    size_t aux;
    while ((cin >> quantidade_jog) && (quantidade_jog != 0))
    {

        cout << "Teste " << testes++ << endl;
        vector<Jogador> jogadores;
        jogadores.reserve(quantidade_jog);
        vector<size_t> pontuacoes(12, 0);
        for (size_t i = 0; i < quantidade_jog; ++i)
        {
            Jogador jogador = Jogador(0, " ");
            cin >> jogador.nome;
            for (size_t j = 0; j < 12; ++j)
            {
                cin >> aux;
                pontuacoes[j] = aux;
            }
            sort(all(pontuacoes));
            for (size_t j = 1; j < 11; ++j)
            {
                jogador.pontuacao += pontuacoes[j];
            }
            jogadores.push_back(jogador);
        }

        sort(all(jogadores));

        int pos = 1;
        int pos_acumulada = 0;
        Jogador* ant = nullptr;

        for (Jogador& j : jogadores)
        {
            if (ant != nullptr)
            {
                pos_acumulada++;
                if (j.pontuacao != ant->pontuacao)
                {
                    pos += pos_acumulada;
                    pos_acumulada = 0;
                }
            }

            cout << pos << " " << j.pontuacao << " " << j.nome << endl;
            ant = &j;
        }

        cout << endl;
    }
    return 0;
}