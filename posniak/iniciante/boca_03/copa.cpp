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
  int k, l;
  cin >> k >> l;
  string saida;
  if ((k <= 8 && l > 8) || ((l <= 8 && k > 8))) {
    saida = "final";
  } else if (((k <= 4 && l > 4) || ((l <= 4 && k > 4))) ||
             ((k <= 12 && l > 12) || ((l <= 12 && k > 12)))) {
    saida = "semifinal";
  } else if ((((k <= 2 && l > 2) || ((l <= 2 && k > 2))) ||
              ((k <= 6 && l > 6) || ((l <= 6 && k > 6)))) ||
             (((k <= 10 && l > 10) || ((l <= 10 && k > 10))) ||
              ((k <= 14 && l > 14) || ((l <= 14 && k > 14))))) {
    saida = "quartas";
  } else {
    saida = "oitavas";
  }

  cout << saida << endl;
  return 0;
}