#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

#define horas 24

class Registro
{
  public:
    string data;
    bool enter;
    int km;

    Registro(string data, int km, bool enter)
    {
        this->data = data;
        this->km = km;
        this->enter = enter;
    }

    bool operator<(const Registro& outro) const
    {
        return data < outro.data;
    }
};

double calcular_valor(const vi& valores, vector<Registro>& registros)
{
    sort(all(registros));
    Registro* ultimoenter = nullptr;
    bool tem_viagem = false;
    double valor = 0.0;

    for (auto& r : registros)
    {
        if (r.enter)
        {
            ultimoenter = &r;
        }
        else
        {
            if (ultimoenter != nullptr)
            {
                int hora = stoi(ultimoenter->data.substr(6, 2));
                int km = abs(r.km - ultimoenter->km);
                valor += (km * valores[hora]) / 100.0 + 1.0;
                tem_viagem = true;
                ultimoenter = nullptr;
            }
        }
    }
    if (tem_viagem)
        return valor + 2.0;
    return 0.0;
}

int main()
{
    fastio;
    string linha;
    getline(cin, linha);
    int cases = stoi(linha);
    for (size_t c = 0; c < cases; ++c)
    {
        do
        {
            getline(cin, linha);
        } while (linha.empty());

        if (c > 0)
            cout << endl;
        vi valores;
        valores.reserve(horas);
        stringstream ss(linha);
        int aux;
        string lixo;
        for (size_t i = 0; i < horas; ++i)
        {
            ss >> aux;
            valores.push_back(aux);
        }

        map<string, vector<Registro>> registros;
        string placa, data;
        int km;
        string ultima_placa = "";
        while (getline(cin, linha) && !linha.empty())
        {
            bool entrando = (linha.find("enter") != string::npos);
            stringstream ss(linha);
            ss.str(linha);
            ss >> placa;
            ss >> data;
            ss >> lixo;
            ss >> km;
            Registro reg(data, km, entrando);

            registros[placa].push_back(reg);
        }

        map<string, double> carros;
        for (auto& r : registros)
        {
            string placa = r.first;
            double valor = calcular_valor(valores, r.second);
            carros[placa] = valor;
        }

        for (auto& c : carros)
        {
            if (c.second != 0)
                cout << fixed << setprecision(2) << c.first << " $" << c.second << endl;
        }
    }
    return 0;
}