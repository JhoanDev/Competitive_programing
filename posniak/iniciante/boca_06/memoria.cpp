#include <array>
#include <atomic>
#include <bits/stdc++.h>
#include <forward_list>
#include <iterator>
#include <vector>

using namespace std;

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

int main()
{
    //_
    int t;
    cin >> t;

    for (int k = 0; k < t; k++)
    {
        int tam, num_op, max, aux;
        cin >> tam >> num_op >> max;
        vector<int> inicial;
        inicial.reserve(tam);
        for (int i = 0; i < tam; i++)
        {
            cin >> aux;
            inicial.push_back(aux);
        }

        vector<int> atual = inicial;
        int b, c;
        for (int i = 0; i < num_op; i++)
        {
            cin >> b >> c;

            if ((atual[b - 1] + c) > max)
            {
                atual = inicial;
                continue;
            }

            atual[b - 1] += c;
        }

        for (int i = 0; i < tam - 1; i++)
        {
            cout << atual[i] << " ";
        }
        cout << atual[tam - 1] << endl;
    }

    return 0;
}