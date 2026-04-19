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

int main() {
  _
  int x, y;
  cin >> x >> y;
  string saida = "dentro";

  if ((x < 0 || x > 432) || (y < 0 || y > 468)) {
    saida = "fora";
  }

  cout << saida << endl;

  return 0;
}