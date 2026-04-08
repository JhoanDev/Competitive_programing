#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    //_
    double a,g,ra,rg;
    cin >> a >> g >> ra >> rg;

    double razaoa,razaog;
    razaoa = a/ra;
    razaog = g/rg;

    (razaoa <= razaog) ? (cout << "A" << endl ): (cout << "G" << endl);


    return 0;
}