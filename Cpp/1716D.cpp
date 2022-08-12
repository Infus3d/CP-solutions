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
  int n, k;
  scanf("%d%d", &n, &k);
  vector<vector<int>> dp(2, vector<int>(n+1, 0));
  vector<int> ans(n+1, 0);
  dp[0][0] = 1;
  int sq = sqrt(2*n), cum = 0;
  for(int j=0; j<=sq; j++){
    fill(all(dp[1]), 0);
    int step = k+j;
    cum += step;
    if(cum > n) break; //cumulative > n
    for(int i=step; i<=n; i++){
      dp[1][i] = (dp[1][i-step] + dp[0][i-step]) % MOD;
    }
    for(int i=0; i<=n; i++){
      ans[i] = (ans[i] + dp[1][i]) % MOD;
      dp[0][i] = dp[1][i];
    }
  }
  for(int i=1; i<=n; i++)
    printf("%d ", ans[i]);
  puts("");
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
