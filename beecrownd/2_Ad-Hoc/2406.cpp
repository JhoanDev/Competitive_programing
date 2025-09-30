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

int main()
{
    _ int testes, i;
    string entrada;
    cin >> testes;
    for (i = 0; i < testes; i++)
    {
        cin >> entrada;
        stack<char> pilha;
        for (char caracter : entrada)
        {
            if (caracter == '{' || caracter == '[' || caracter == '(')
                pilha.push(caracter);
            else
            {
                if (!pilha.empty())
                {
                    char topo = pilha.top();
                    if (topo == '{' && caracter == '}')
                        pilha.pop();
                    else if (topo == '[' && caracter == ']')
                        pilha.pop();
                    else if (topo == '(' && caracter == ')')
                        pilha.pop();
                    else
                    {
                        pilha.push(caracter);
                    }
                }
                else
                {
                    pilha.push(caracter);
                }
            }
        }
        pilha.empty() ? (cout << "S" << endl) : (cout << "N" << endl);
    }

    return 0;
}