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

int n, m, k, vis[N];
vector<pii> E[N];
ll path[N][N], dp[N*5];
ll s[N*5], e[N*5], t[N*5]; //t for ci[t]y KEKL

bool ok(ll D){
  if(D < 0LL) return false;
  memset(dp, -1LL, sizeof(dp));
  
  for(int i=k; i>=1; i--){
    ll costsofar = 0, maxsofar = (ll)1e18;
    for(int j=i; j<=k; j++){
      if(j == i) costsofar += path[1][t[j]];
      else costsofar += path[t[j-1]][t[j]];
      
      maxsofar = min(maxsofar, s[j] + D - costsofar);
      if(maxsofar < e[j])  break;
      
      if(j == k)
        dp[i] = max(dp[i], maxsofar);
      else if((dp[j+1] >= e[j] + costsofar + path[t[j]][1]))
        dp[i] = max(dp[i], min(dp[j+1] - (costsofar + path[t[j]][1]), maxsofar));
    }
  }
  
  return dp[1] >= e[1];
}

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=m; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    E[a].pb({b, c});
    E[b].pb({a, c});
  }
  scanf("%d", &k);
  for(int i=1; i<=k; i++)
    scanf("%lld%lld%lld", &s[i], &t[i], &e[i]);
  
  for(int i=1; i<=n; i++){
    memset(vis, 0, sizeof(vis));
    memset(path[i], 60, sizeof(path[i]));
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    
    Q.push({0, i});
    path[i][i] = 0LL;
    while(!Q.empty()){
      auto tr = Q.top(); Q.pop();
      if(vis[tr.ss]) continue;
      
      vis[tr.ss] = 1;
      for(pii j : E[tr.ss]){
        if(path[i][j.ff] > tr.ff + j.ss){
          path[i][j.ff] = tr.ff + j.ss;
          Q.push({path[i][j.ff], j.ff});
        }
      }
    }
  }
  
  ll l = -1, r = (ll)1e18;
  while(l + 1 < r){
    if(ok(mid(l, r)))
      r = mid(l, r);
    else
      l = mid(l, r);
  }
  printf("%lld\n", r);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
