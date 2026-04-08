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
  double banca_1[4], banca_2[4], banca_3[4];
  cin >> banca_1[0] >> banca_1[1] >> banca_1[2] >> banca_1[3];
  cin >> banca_2[0] >> banca_2[1] >> banca_2[2] >> banca_2[3];
  cin >> banca_3[0] >> banca_3[1] >> banca_3[2] >> banca_3[3];

  double total_b1, total_b2, total_b3;

  total_b1 = (banca_1[0] + banca_1[1]) -
             ((banca_1[0] + banca_1[1]) * (banca_1[2] / 100));
  total_b2 = (banca_2[0] + banca_2[1]) -
             ((banca_2[0] + banca_2[1]) * (banca_2[2] / 100));
  total_b3 = (banca_3[0] + banca_3[1]) -
             ((banca_3[0] + banca_3[1]) * (banca_3[2] / 100));
  cout << fixed << setprecision(2);
  if (total_b1 < total_b2 && total_b1 < total_b3) {
    cout << "R$ " << total_b1 << " Banca 1";
  }
  else if (total_b2 < total_b1 && total_b2 < total_b3) {
    cout << "R$ " << total_b2 << " Banca 2";
  }
  else {
    cout << "R$ " << total_b3 << " Banca 3";
  }
  cout << endl;
  return 0;
}