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

int n, k, half[N][33];
ll dp[N][33];

void solve(){
  scanf("%d%d", &n, &k);
  for(int i=1; i<=n; i++){
    int a; scanf("%d", &a);
    half[i][0] = a;
    for(int j=1; j<32; j++){
      half[i][j] = half[i][j-1] / 2;
      dp[i][j] = -1e18;
    }
    dp[i][0] = -1e18;
  }
  for(int i=0; i<32; i++)
    dp[0][i] = -1e18;
  dp[0][0] = 0;
  
  for(int i=1; i<=n; i++){
    for(int j=0; j<32; j++){
      dp[i][j] = dp[i-1][j] + half[i][j] - k;
      if(j > 0)
        dp[i][j] = max(dp[i][j], dp[i-1][j-1] + half[i][j]);
      if(j == 31)
        dp[i][j] = max(dp[i][j], dp[i-1][j] + half[i][j]);
    }
  }
  
  ll ans = -1e18;
  for(int i=0; i<32; i++)
    ans = max(ans, dp[n][i]);
  printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  cin >> testcase;
  while(testcase--){
    solve();
  }
  return 0;
}
