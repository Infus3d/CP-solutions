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

const int N = 1e3+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, k, a[N], par[N], len[N];
int cycle[N], cycleLength, depth[N];

int find(int x){
  if(par[x] == x)
    return x;
  return par[x] = find(par[x]);
}

void dfs(int x, int dep){
  depth[x] = dep;
  if(depth[a[x]] != 0 && cycle[find(x)] == 0)
    cycle[find(x)] = dep - depth[a[x]] + 1;
  else
    dfs(a[x], dep+1);
}

void solve(){
  scanf("%d%d", &n, &k);
  for(int i=1; i<=n; i++) par[i] = i, len[i] = 1;
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    if(find(i) != find(a[i])){
      len[find(a[i])] += len[find(i)];
      par[find(i)] = find(a[i]);
    }
  }
  
  vector<pii> v;
  for(int i=1; i<=n; i++){
    if(!cycle[find(i)]){
      dfs(i, 1);
      v.pb({cycle[find(i)], len[find(i)]});
    }
  }
  
  vector<int> dp(k+1);
  dp[0] = 1;
  for(pii j : v){
    int p = k;
    for(int i=k; i>=0; i--){
      if(dp[i] == 0) continue;
      while(p >= 0 && i+j.ss < p) p--;
      while(p >= 0 && p >= i+j.ff) dp[p] = 1, p--;
    }
  }
  
  for(int i=k; i>=0; i--)
    if(dp[i] == 1){
      printf("%d\n", i);
      return;
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
