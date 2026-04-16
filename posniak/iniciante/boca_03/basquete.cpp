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
  int d, pts;
  cin >> d;

  if (d <= 800) {
    pts = 1;
  } else if (d <= 1400) {
    pts = 2;
  } else {
    pts = 3;
  }

  cout << pts << endl;
  return 0;
}