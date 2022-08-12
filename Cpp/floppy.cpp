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

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int dp[10002][2];

void solve(){
  int n; scanf("%d", &n);
  for(int i=1; i<=n; i++){
    int t, m; scanf("%d%d", &t, &m);
    vector<pii> a(m);
    for(int j=0; j<m; j++)
      scanf("%d%d", &a[j].ff, &a[j].ss);
    for(int j=0; j<=t; j++){
      dp[j][0] = 1;
      dp[j][1] = 0;
    }
    for(int j=0; j<m; j++){
      for(int k=0; k<=t; k++){
        int diff = a[j].ss - a[j].ff;
        if(k-diff >= 0) dp[k-diff][1] |= dp[k][0];
        if(k+diff <= t) dp[k+diff][1] |= dp[k][0];
      }
      for(int k=0; k<=t; k++){
        dp[k][0] = dp[k][1];
        dp[k][1] = 0;
      }
    }
    int ans = 0;
    for(int j=0; j<=t; j++)
      ans |= dp[j][0];
    if(ans == 0){
      puts("impossible");
      return;
    }
  }
  puts("possible");
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
