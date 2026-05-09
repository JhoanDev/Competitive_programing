#include <bits/stdc++.h>
#include <iterator>
#include <vector>

using namespace std;

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

int main()
{
    //_
    int tam, aux, anterior = 0;
    vector<int> seq;
    cin >> tam;
    seq.reserve(tam);

    for (int i = 0; i < tam; i++)
    {
        cin >> aux;
        seq.push_back(aux);
    }

    int marcados = 0;
    for (int i = 0; i < tam; i++)
    {
        if (anterior != seq[i])
        {
            marcados++;
            anterior = seq[i];
        }
    }

    cout << marcados << endl;

    return 0;
}