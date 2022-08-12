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

const int N = 4e2+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, k, dp[N][N];
int track[N][N], f[N][N];
vector<pii> E[N];
pii p[N];

void dfs(int x, int par){
  int cur = 0, m = sz(E[x]);
  for(pii u : E[x]){
    if(u.ff == par){
      p[x] = u;
      continue;
    }
    dfs(u.ff, x);
  }
  
  for(pii u : E[x])
    if(u.ff != par){
      if(cur == 0){
        for(int i=0; i<=m; i++)
          for(int j=0; j<=k; j++){
            f[i][j] = (i == cur ? dp[u.ff][j] : 1000);
            if(i == cur){
              f[i][j] = dp[u.ff][j];
              //~ printf("blalala f[i][j]:%d\n", f[i][j]);
            }
          }
      }
      else{
        for(int i=0; i<=k; i++)
          for(int j=0; j<=i; j++)
            if(f[cur][i] > f[cur-1][i-j] + dp[u.ff][j])
              f[cur][i] = f[cur-1][i-j] + dp[u.ff][j];
      }
      cur++;
  }
  
  if(m == 1 && par != 0){
    f[cur][0] = 0;
    for(int i=1; i<=k; i++)
      f[cur][i] = 1000;
    cur++;
  }
  
  for(int i=0; i<k; i++)
    dp[x][i+1] = f[cur-1][i];
  dp[x][0] = 1;  
  
  //~ printf("x:%d\n", x);
  //~ for(int i=0; i<=k; i++)
    //~ printf("dp[x][i]:%d, i:%d\n", dp[x][i], i);
  
  //~ for(int i=0; i<cur; i++){
    //~ for(int j=0; j<=k; j++)
      //~ printf("%d ", f[i][j]);
    //~ puts("");
  //~ }
}

void find(int x, int par, int val){
  if(val == 0){
    printf("%d ", p[x].ss);
    return;
  }
  
  int cur = 0, m = sz(E[x]);
  for(pii u : E[x]){
    if(u.ff == p[x].ff) continue;
    if(cur == 0){
      for(int j=0; j<=k; j++){
        f[0][j] = dp[u.ff][j];
        track[0][j] = j;
      }
      for(int i=1; i<=m; i++)
        for(int j=0; j<=k; j++)
          f[i][j] = 1000;
    }
    else{
      for(int i=0; i<=k; i++)
        for(int j=0; j<=i; j++)
          if(f[cur][i] > f[cur-1][i-j] + dp[u.ff][j]){
            f[cur][i] = f[cur-1][i-j] + dp[u.ff][j];
            track[cur][i] = j;
          }
    }
    cur++;
  }
  
  vector<int> v;
  int temp = cur-1, tval = val-1;
  while(temp >= 0){
    v.pb(track[temp][tval]);
    tval = tval - track[temp][tval];
    temp--;
  }
  reverse(all(v));
  
  //~ printf("x:%d\n", x);
  //~ for(int i : v)
    //~ printf("%d ", i);
  //~ puts("");
  int cn = 0;
  for(pii u : E[x])
    if(u.ff != p[x].ff){
      find(u.ff, x, v[cn]);
      cn++;
    }
}

void solve(){
  scanf("%d%d", &n, &k);
  for(int i=1; i<n; i++){
    int a, b; 
    scanf("%d%d", &a, &b);
    E[a].pb({b, i});
    E[b].pb({a, i});
  }
  dfs(1, 0);
  
  int mn = 1000, ind = -1;
  for(int i=1; i<=n; i++)
    if(mn > dp[i][k] + (i != 1)){
      mn = dp[i][k] + (i != 1);
      ind = i;
    }
  
  if(ind == -1){
    puts("0");
    return;
  }
  
  printf("%d\n", mn);
  if(ind > 1) printf("%d\n", p[ind].ss);
  find(ind, 0, k);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
