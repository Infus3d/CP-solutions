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

const int N = 2e3+2;
const int K = 2e5;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int fac[K+2], invfac[K+2];
int n, m, q, a, b;
int dp[N];
vector<pii> blocks;

int mul(int x, int y){
  return (1LL * x * y) % MOD;
}

int sub(int x, int y){
  return (x + MOD - y) % MOD;
}

int bmod(int x, int degree){
  if(degree == 0) return 1;
  int t = bmod(x, degree/2);
  t = mul(t, t);
  if(degree % 2 == 1) t = mul(t, x);
  return t;
}

void precalc(){
  fac[0] = 1;
  for(int i=1; i<=K; i++) fac[i] = mul(fac[i-1], i);
  invfac[K] = bmod(fac[K], MOD-2);
  for(int i=K-1; i>=0; i--) invfac[i] = mul(invfac[i+1], i+1);
}

int nCr(int x1, int x2, int y1, int y2){ //assuming x1 >= x2 and y1 >= y2
  int nn = (x1 - x2) + (y1 - y2);
  int rr = (x1 - x2);
  return mul(fac[nn], mul(invfac[nn-rr], invfac[rr]));
}

void solve(){
  scanf("%d%d%d", &n, &m, &q);
  for(int i=1; i<=q; i++){
    scanf("%d%d", &a, &b);
    blocks.pb({a, b});
  }
  
  blocks.pb({n, m});
  sort(all(blocks));
  
  precalc();
  for(int i=0; i<=q; i++){
    int xi = blocks[i].ff;
    int yi = blocks[i].ss;
    dp[i] = nCr(xi, 1, yi, 1);
    
    for(int j=0; j<i; j++){
      int xj = blocks[j].ff;
      int yj = blocks[j].ss;
      if(xj <= xi && yj <= yi)
        dp[i] = sub(dp[i], mul(dp[j], nCr(xi, xj, yi, yj)));
    }
  }
  printf("%d\n", dp[q]);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
