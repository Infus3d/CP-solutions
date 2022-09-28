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

int n, d[N];
pair<int, int> dp[N][2];
int ans, sum;
vector<int> E[N];

void dfs(int x, int par){
  dp[x][1] = {1, sz(E[x])};
  for(int i : E[x]){
    if(i != par){
      dfs(i, x);
      dp[x][1].ff += dp[i][0].ff;
      dp[x][1].ss += dp[i][0].ss;
      pair<int, int> cur = {-1, -1};
      if(dp[i][0].ff == dp[i][1].ff) cur = min(dp[i][0], dp[i][1]);
      else cur = max(dp[i][0], dp[i][1]);
      dp[x][0].ff += cur.ff;
      dp[x][0].ss += cur.ss;
    }
  }
}

void dfs_assign(int x, int par, int t){
  d[x] = (t ? sz(E[x]) : 1);
  sum += d[x];
  for(int i : E[x]){
    if(i != par){
      if(t == 1){
        dfs_assign(i, x, 0);
      }
      else{
        int tt = -1;
        if(dp[i][0].ff == dp[i][1].ff) tt = (dp[i][0].ss > dp[i][1].ss);
        else tt = (dp[i][0].ff < dp[i][1].ff);
        dfs_assign(i, x, tt);
      }
    }
  }
}

void solve(){
  scanf("%d", &n);
  for(int i=1; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    E[a].push_back(b);
    E[b].push_back(a);
  }
  if(n == 2){
    printf("2 2\n1 1\n");
    return;
  }
  dfs(1, 0);
  ans = max(dp[1][0].ff, dp[1][1].ff), sum = 0;
  int tt = -1;
  if(dp[1][0].ff == dp[1][1].ff) tt = (dp[1][0].ss > dp[1][1].ss);
  else tt = (dp[1][0].ff < dp[1][1].ff);
  dfs_assign(1, 0, tt);
  printf("%d %d\n", ans, sum);
  for(int i=1; i<=n; i++){
    printf("%d ", d[i]);
  }
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
