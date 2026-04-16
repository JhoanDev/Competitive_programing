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
  int x1, x2, x3, x4, x5;
  int y1, y2, y3, y4, y5;
  cin >> x1 >> x2 >> x3 >> x4 >> x5;
  cin >> y1 >> y2 >> y3 >> y4 >> y5;
  char saida = 'Y';

  if (x1 == y1 || x2 == y2 || x3 == y3 || x4 == y4 || x5 == y5) {
    saida = 'N';
  }

  cout << saida << endl;
  return 0;
}