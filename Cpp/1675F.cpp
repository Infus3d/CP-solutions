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

int d[N], depth[N];
long long dp[N];
vector<int> E[N];

void dfs(int u, int par){
  depth[u] = depth[par]+1;
  for(int v : E[u]){
    if(v != par){
      dfs(v, u);
      if(d[v] || dp[v] > 0)
        dp[u] += dp[v] + 2;
    }
  }
}

void solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i=1; i<=n; i++){
    E[i].clear();
    d[i] = 0;
    dp[i] = 0;
  }
  
  int x, y;
  scanf("%d%d", &x, &y);
  for(int i=0; i<k; i++){
    int a;
    scanf("%d", &a);
    d[a] = 1;
  }
  
  for(int i=0; i<n-1; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    E[a].push_back(b);
    E[b].push_back(a);
  }
  
  d[x] = d[y] = 1;
  dfs(y, 0);
  printf("%lld\n", dp[y] - (depth[x] - depth[y]));
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
