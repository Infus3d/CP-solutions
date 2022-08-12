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

const int N = 1e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, P[N][19], lvl[N], p[N];
vector<int> E[N];

void dfs(int x, int y){
  P[x][0] = y;
  lvl[x] = lvl[y]+1;
  for(int i : E[x])
    if(i != y)
      dfs(i, x);
}

void build_lca(){
  for(int i=0; i<=n; i++)
    for(int j=1; j<19; j++)
      P[i][j] = 0;
  for(int j=18; j>=0; j--)
    for(int i=1; i<=n; i++)
      if(P[i][j-1] > 0)
        P[i][j] = P[P[i][j-1]][j-1];
}

int lca(int x, int y){
  if(lvl[x] < lvl[y])
    swap(x, y);
  
  for(int i=18; i>=0; --i)
    if(lvl[x] - (1<<i) >= lvl[y])
      x = P[x][i];
  
  if(x == y) return x;
  
  for(int i=18; i>=0; --i)
    if(P[x][i] > 0 && P[x][i] != P[y][i])
      x = P[x][i], y = P[y][i];
  
  return P[x][0];
}

void solve(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) E[i].clear();
  for(int i=1; i<n; i++){
    int a, b; scanf("%d%d", &a, &b);
    E[a].pb(b); E[b].pb(a);
  }
  for(int i=1; i<=n; i++)
    scanf("%d", &p[i]);
  dfs(1, 0);
  build_lca();
  
  int ans = 1;
  for(int i=2; i<=n; i++){
    int a = p[i-1], b = p[i];
    int c = lca(a, b);
    if(abs(lvl[c]-lvl[a]) + abs(lvl[c]-lvl[b]) > 3)
      ans = 0;
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
