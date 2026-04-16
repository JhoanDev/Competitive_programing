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
  int a, b, c, saida;
  cin >> a >> b >> c;

  if ((b - a) < (c - b)) {
    saida = 1;
  } else if ((b - a) > (c - b)) {
    saida = -1;
  } else {
    saida = 0;
  }

  cout << saida << endl;
  return 0;
}