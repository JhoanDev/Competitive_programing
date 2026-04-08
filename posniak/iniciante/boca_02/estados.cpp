#include <bits/stdc++.h>
#include <set>
#include <string>

using namespace std;

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
  //_
  set<string> estados;
  estados.insert("para");
  estados.insert("roraima");
  estados.insert("acre");
  estados.insert("amapa");
  estados.insert("amazonas");
  estados.insert("rondonia");
  estados.insert("tocantins");

  string entrada;
  cin >> entrada;

  estados.count(entrada) ? (cout << "Regiao Norte" << endl ): (cout << "Outra regiao" << endl);

  return 0;
}