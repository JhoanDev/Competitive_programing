#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

int main()
{
    _ int tam, i, j;
    cin >> tam;
    vector<vector<int>> matriz(tam, vector<int>(tam));
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            cin >> matriz[i][j];
        }
    }
    set<int> especies;
    int a, b;
    for (i = 1; i <= tam * 2; i++)
    {
        cin >> a >> b;
        especies.insert(matriz[a-1][b-1]);
    }
    cout << especies.size() << endl;

    return 0;
}