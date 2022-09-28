#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
#define all(x)	x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

//https://cp-algorithms.com/algebra/phi-function.html#implementation
vector<int> phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

void solve(){
  int n; scanf("%d", &n);
  vector<int> t = phi_1_to_n(n);
  //~ printf("%d\n", t[n]);
  int ans = 0;
  for(int i=1; i<=n-2; i++){
    int ab = n-i;
    ll thistime = 0;
    for(int j=1; j*j<=ab; j++){
      if(ab % j) continue;
      ll u = j, v = ab/j;
      int gcdu = __gcd(i, (int)u);
      int gcdv = __gcd(i, (int)v);
      if(u < ab)
        thistime = (thistime + ((u / gcdu) * t[ab/u]) % MOD) % MOD;
      if(v != u && v < ab)
        thistime = (thistime + ((v / gcdv) * t[ab/v]) % MOD) % MOD;
    }
    ans = (ans + (thistime * i)%MOD)%MOD;
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
