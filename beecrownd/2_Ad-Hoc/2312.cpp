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

class Pais
{

public:
    string nome;
    int ouro;
    int prata;
    int bronze;

    Pais(string n, int o, int p, int b) : nome(n), ouro(o), prata(p), bronze(b) {}

    bool operator<(const Pais &outro) const
    {
        if (this->ouro != outro.ouro)
        {
            return this->ouro > outro.ouro;
        }
        if (this->prata != outro.prata)
        {
            return this->prata > outro.prata;
        }
        if (this->bronze != outro.bronze)
        {
            return this->bronze > outro.bronze;
        }
        return this->nome < outro.nome;
    }
};

ostream &operator<<(ostream &os, const Pais &p)
{
    os << p.nome << " " << p.ouro << " " << p.prata << " " << p.bronze;
    return os;
};

int main()
{
    _ int qnt_paises, ouro, prata, bronze, i;
    string nome;
    cin >> qnt_paises;
    vector<Pais> paises;
    paises.reserve(qnt_paises);
    for (i = 0; i < qnt_paises; i++)
    {
        cin >> nome >> ouro >> prata >> bronze;
        paises.push_back(Pais(nome, ouro, prata, bronze));
    }
    sort(paises.begin(), paises.end());
    for (i = 0; i < qnt_paises; i++)
    {
        cout << paises.at(i) << endl;
    }

    return 0;
}