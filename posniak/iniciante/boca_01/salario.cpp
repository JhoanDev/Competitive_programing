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
  string rest;
  cin >> rest;

  double s, v;
  cin >> s;
  cin >> v;

  cout << "TOTAL = R$ " << fixed << setprecision(2) << (s + v * 0.15) << endl;
  return 0;
}