#include <bits/stdc++.h>

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

// aristovaldo(a),fabiana(f),daniel(d),bruna(b),carlos(c)

const string a = "aristovaldo";
const string f = "fabiana";
const string d = "daniel";
const string b = "bruna";
const string c = "carlos";

int main() {
  //_
  string n1, n2;
  cin >> n1 >> n2;

  string saida = "";
  // aristovaldo
  if (n1 == a && n2 == f)
    saida = "irmao";
  if (n1 == f && n2 == a)
    saida = "irma";

  if (n1 == a && n2 == d)
    saida = "pai";
  if (n1 == d && n2 == a)
    saida = "filho";

  if (n1 == a && n2 == b)
    saida = "pai neto";
  if (n1 == b && n2 == a)
    saida = "avo filha";

  if (n1 == a && n2 == c)
    saida = "avo filho";
  if (n1 == c && n2 == a)
    saida = "pai neto";

  // fabiana

  if (n1 == f && n2 == d)
    saida = "mae";
  if (n1 == d && n2 == f)
    saida = "filho";

  if (n1 == f && n2 == b)
    saida = "mae neta";
  if (n1 == b && n2 == f)
    saida = "avo filha";

  if (n1 == f && n2 == c)
    saida = "avo";
  if (n1 == c && n2 == f)
    saida = "neto";

  // daniel

  if (n1 == d && n2 == b)
    saida = "irmao";
  if (n1 == b && n2 == d)
    saida = "irma";

  if (n1 == d && n2 == c)
    saida = "neto";
  if (n1 == c && n2 == d)
    saida = "avo";

  // bruna

  if (n1 == b && n2 == c)
    saida = "mae neta";
  if (n1 == c && n2 == b)
    saida = "avo filho";

  cout << saida << endl;

  return 0;
}