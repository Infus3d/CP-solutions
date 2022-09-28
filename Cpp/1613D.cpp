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

void solve(){
  int n;
  scanf("%d", &n);
  vector<int> a(n), cnt(n+2), pw(n+1);
  pw[0] = 1;
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    pw[i+1] = (pw[i]*2) % MOD;
  }
  int ans = 0;
  vector<int> dp(n+1, 0);
  dp[0] = 1;
  for(int i=0; i<n; i++){
    cnt[a[i]]--;
    if(a[i] > 0){
      int both = cnt[a[i]] + (a[i] > 1 ? cnt[a[i]-2] : 0);
      int skips = (1ll * pw[both] * dp[a[i]-1]) % MOD;
      ans = (ans + skips) % MOD;
    }
    if(a[i] < n){
      int stalls = dp[a[i]+1];
      ans = (ans + stalls) % MOD;
      dp[a[i]+1] = (dp[a[i]+1] + stalls) % MOD;
    }
    ans = (ans + dp[a[i]]) % MOD;
    if(a[i] < n)
      dp[a[i]+1] = (dp[a[i]+1] + dp[a[i]]) % MOD;
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
