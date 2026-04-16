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

int main() {
  //_
  int dia, mes;
  cin >> dia >> mes;
  string saida;

  if ((mes == 3 && dia >= 21) || (mes == 4 && dia <= 20))
    saida = "aries";
  else if ((mes == 4 && dia >= 21) || (mes == 5 && dia <= 20))
    saida = "touro";
  else if ((mes == 5 && dia >= 21) || (mes == 6 && dia <= 20))
    saida = "gemeos";
  else if ((mes == 6 && dia >= 21) || (mes == 7 && dia <= 22))
    saida = "cancer";
  else if ((mes == 7 && dia >= 23) || (mes == 8 && dia <= 22))
    saida = "leao";
  else if ((mes == 8 && dia >= 23) || (mes == 9 && dia <= 22))
    saida = "virgem";
  else if ((mes == 9 && dia >= 23) || (mes == 10 && dia <= 22))
    saida = "libra";
  else if ((mes == 10 && dia >= 23) || (mes == 11 && dia <= 21))
    saida = "escorpiao";
  else if ((mes == 11 && dia >= 22) || (mes == 12 && dia <= 21))
    saida = "sagitario";
  else if ((mes == 12 && dia >= 22) || (mes == 1 && dia <= 19))
    saida = "capricornio";
  else if ((mes == 1 && dia >= 20) || (mes == 2 && dia <= 18))
    saida = "aquario";
  else if ((mes == 2 && dia >= 19) || (mes == 3 && dia <= 20))
    saida = "peixes";

  cout << saida << endl;

  return 0;
}