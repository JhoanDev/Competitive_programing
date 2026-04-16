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
  int r1x0, r1x1, r1y0, r1y1;
  int r2x0, r2x1, r2y0, r2y1;
  cin >> r1x0 >> r1y0 >> r1x1 >> r1y1;
  cin >> r2x0 >> r2y0 >> r2x1 >> r2y1;
  int colisao = 1;

  if (r1x1 < r1x0) {
    colisao = 0;
  } else if (r1x0 > r2x1) {
    colisao = 0;
  } else if (r1y1 < r2y0) {
    colisao = 0;
  } else if (r1y0 > r2y1) {
    colisao = 0;
  }

  cout << colisao << endl;
  return 0;
}