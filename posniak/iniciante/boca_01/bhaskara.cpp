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
  int a, b, c;
  cin >> a >> b >> c;

  double delta = b * b - (4 * a * c);
  double x1 = (-b + sqrt(delta)) / (2 * a);
  double x2 = (-b - sqrt(delta)) / (2 * a);

  cout << fixed << setprecision(3) << x1 << " " << x2 << endl;

  return 0;
}