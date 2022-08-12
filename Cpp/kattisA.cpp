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
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0;}

ll n, dig[11], a;
ll dp[2][20][2];
vector<ll> d, v;

void solve(){
  scanf("%lld", &a);
  ll m = a;
  while(m > 0) d.pb(m%10), m /= 10;
  d.pb(0);
  reverse(all(d));
  
  int n = sz(d)-1;
  v.resize(n+1);
  for(int i=1; i<=n; i++) v[i] = v[i-1]*10 + d[i];
  
  int tot = 0;
  memset(dig, 0, sizeof(dig));
  for(int i=1; i<=n; i++) dig[d[i]] = 1;
  for(int i=0; i<10; i++) tot += dig[i];
  if(tot == 10){
    puts("Impossible");
    return;
  }
  //~ if(tot == 9 && !dig[0]){
    //~ puts("0");
    //~ return;
  //~ }
  
  memset(dp[0], 61, sizeof(dp[0]));
  dp[0][0][1] = 0;
  for(int i=1; i<10; i++)
    if(dig[i] == 0){
      dp[0][0][0] = i;
      break;
    }
  
  for(int i=1; i<=n; i++){
    for(int j=0; j<2; j++){
      for(int k=0; k<10; k++){
        if(dig[k] == 1) continue;
        if(j == 1 && k < d[i]) continue;
        int newj = (j == 1 && k == d[i]);
        assert(newj == 0);
        umin(dp[0][i][newj], dp[0][i-1][j]*10 + k);
      }
    }
  }
  
  memset(dp[1], -1, sizeof(dp[1]));
  dp[1][0][1] = 0;
  for(int i=1; i<=n; i++){
    for(int j=0; j<2; j++){
      if(dp[1][i-1][j] == -1) continue;
      for(int k=0; k<10; k++){
        if(dig[k] == 1) continue;
        if(j == 1 && k > d[i]) continue;
        int newj = (j == 1 && k == d[i]);
        assert(newj == 0);
        umax(dp[1][i][newj], (dp[1][i-1][j]*10 + k));
      }
    }
    umax(dp[1][i][0], 0LL);
  }
  
  ll big = dp[0][n][0];
  ll smol = dp[1][n][0];
  //~ printf("%lld %lld\n", smol, big);
  
  if(abs(a-big) == abs(a-smol))
    printf("%lld %lld\n", smol, big);
  else if(abs(a-big) < abs(a-smol))
    printf("%lld\n", big);
  else
    printf("%lld\n", smol);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
