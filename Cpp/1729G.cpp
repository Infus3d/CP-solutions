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

int n, m;
char s[N], t[N];

void solve(){
  scanf("%s%s", s, t);
  n = strlen(s), m = strlen(t);
  vector<int> a(n, 0);
  for(int i=0; i<n; i++){
    bool ok = true;
    for(int j=0; j<m; j++){
      if(i+j >= n || s[i+j] != t[j]){
        ok = false;
        break;
      }
    }
    if(ok) a[i+m-1] = 1;
  }
  vector<vector<int>> dp(2, vector<int>(n+1, 501));
  vector<vector<int>> cnt(2, vector<int>(n+1, 0));
  dp[0][0] = 0;
  cnt[0][0] = 1;
  for(int i=1; i<=n; i++){
    if(a[i-1]){
      for(int j=i-m+1; j<i; j++){
        if(!a[j-1]) continue;
        if(dp[1][j] < dp[0][i]){
          dp[0][i] = dp[1][j];
          cnt[0][i] = cnt[1][j];
        } else if(dp[1][j] == dp[0][i]){
          cnt[0][i] = (cnt[0][i] + cnt[1][j]) % MOD;
        }
      }
      cnt[1][i] = cnt[0][i-m];
      dp[1][i] = dp[0][i-m]+1;
      if(dp[0][i] > dp[1][i]){
        dp[0][i] = dp[1][i];
        cnt[0][i] = cnt[1][i];
      } else if(dp[0][i] == dp[1][i]){
        cnt[0][i] = (cnt[0][i] + cnt[1][i]) % MOD;
      }
    } else {
      dp[0][i] = dp[0][i-1];
      cnt[0][i] = cnt[0][i-1];
    }
  }
  printf("%d %d\n", dp[0][n], cnt[0][n]);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
