#include <bits/stdc++.h>
#include <iomanip>

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
  double salario, percentual, reajuste;
  cin >> salario;

  if (salario >= 0) {
    if (salario <= 400.00) {
      percentual = 0.15;
      reajuste = salario * percentual;
    } else if (salario <= 800.00) {
      percentual = 0.12;
      reajuste = salario * percentual;
    } else if (salario <= 1200.00) {
      percentual = 0.10;
      reajuste = salario * percentual;
    } else if (salario <= 2000.00) {
      percentual = 0.07;
      reajuste = salario * percentual;
    } else {
      percentual = 0.04;
      reajuste = salario * percentual;
    }
  }

  cout << fixed << setprecision(2) << "Novo salario: " << salario + reajuste
       << "\nReajuste ganho: " << reajuste
       << "\nEm percentual: " << setprecision(0) << percentual * 100 << " %" << endl;

  return 0;
}