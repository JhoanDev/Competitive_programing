#include <bits/stdc++.h>
#include <cmath>
#include <iterator>
#include <type_traits>
#include <vector>

using namespace std;

#define endl '\n'
#define f first
#define s second

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

void imprimir_vetor(const vector<double>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << fixed << setprecision(4) << v[i] << ' ';
    }
}

double passa_alta(double x_ant, double x, double y_ant, double alpha)
{
    return (alpha * (y_ant + x - x_ant));
}

double filtro_notch(double b0, double x, double b1, double x_ant, double b2, double x_ant2, double a1, double y_ant, double a2, double y_ant2)
{
    return (b0 * x + b1 * x_ant + b2 * x_ant2 - a1 * y_ant - a2 * y_ant2);
}

int main()
{
    //_
    int tam, i;
    cin >> tam;
    vector<double> x;
    x.reserve(tam);

    for (i = 0; i < tam; i++)
    {
        double aux;
        cin >> aux;
        x.push_back(aux);
    }

    double alpha, w, r;
    cin >> alpha >> w >> r;

    vector<double> y(tam);

    y[0] = passa_alta(0, x[0], 0, alpha);

    for (i = 1; i < tam; i++)
    {
        y[i] = passa_alta(x[i - 1], x[i], y[i - 1], alpha);
    }
    for (i = 0; i < tam; i++)
    {
        x[i] = y[i];
    }

    double b0, b1, b2, a1, a2;
    b0 = 1;
    b1 = -2 * cos(w);
    b2 = 1;
    a1 = -2 * r * cos(w);
    a2 = r * r;

    y[0] = filtro_notch(b0, x[0], b1, 0, b2, 0, a1, 0, a2, 0);
    y[1] = filtro_notch(b0, x[1], b1, x[0], b2, 0, a1, y[0], a2, 0);

    for (i = 2; i < tam; i++)
    {
        y[i] = filtro_notch(b0, x[i], b1, x[i - 1], b2, x[i - 2], a1, y[i - 1], a2, y[i - 2]);
    }

    imprimir_vetor(y);

    return 0;
}