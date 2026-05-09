#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

int main()
{
    //_
    int qnt_pontos, aux;
    cin >> qnt_pontos;
    vector<int> pontos;
    pontos.reserve(qnt_pontos);
    for (int i = 0; i < qnt_pontos; i++)
    {
        cin >> aux;
        pontos.push_back(aux);
    }

    sort(pontos.begin(), pontos.end());

    int ponto_mais_alto = pontos.at(qnt_pontos - 1);

    int rio, submerso;
    cin >> rio >> submerso;

    if ((rio - submerso) > ponto_mais_alto)
        cout << "SIM\n";
    else
        cout << "NAO\n";

    return 0;
}