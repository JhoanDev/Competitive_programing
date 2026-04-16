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
  string avenida, cor;
  cin >> avenida >> cor;
  string saida = "gatou";

  // puc = pretos
  // vale = amarelos e pretos
  // saude = brancos
  // agronomia e marinha = tricolores
  // redenção = cinzas e tricolores
  // outros = brancos

  if (avenida == "protasio") {
    if (cor == "branco") {
      saida = "saude sesc";
    }
    if (cor == "cinza" || cor == "tricolor") {
      saida = "redencao";
    }
  }
  if (avenida == "ipiranga") {
    if (cor == "preto") {
      saida = "puc";
    }
    if (cor == "branco") {
      saida = "saude";
    }
    if (cor == "tricolor") {
      saida = "marinha";
    }
  }
  if (avenida == "bento") {
    if (cor == "preto") {
      saida = "puc vale";
    }
    if (cor == "amarelo") {
      saida = "vale";
    }
    if (cor == "tricolor") {
      saida = "agronomia";
    }
  }

  cout << saida << endl;
  return 0;
}