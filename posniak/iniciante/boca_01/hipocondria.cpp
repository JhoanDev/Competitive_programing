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

  int h1, m1, s1;
  cin >> h1 >> m1 >> s1;

  int h2, m2, s2;
  cin >> h2 >> m2 >> s2;

  int seg = (h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1);
  cout << seg << " segundo(s)" << endl;
  return 0;
}