#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

#define MAX 1000000

int main()
{
    //_
    vector<int> parafusos(MAX);
    int aux = 0;
    while (cin >> aux)
    {
        parafusos[aux]++;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (parafusos.at(i) == 1)
        {
            cout << "N" << i << " tem apenas um exemplar\n";
        }
        else if (parafusos.at(i) > 1)
        {
            cout << "N" << i << " tem " << parafusos.at(i) << " exemplares\n";
        }
    }

    return 0;
}