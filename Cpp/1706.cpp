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

int n, m, q, anc[N], depth[N];
int st[N][18], P[N][18], M[N][18]; 
vector<pii> E[N];

int find(int x){
  if(anc[x] == x)
    return x;
  return anc[x] = find(anc[x]);
}

void dfs(int u, int par, int cost){
  P[u][0] = par;
  M[u][0] = cost;
  depth[u] = depth[par]+1;
  for(auto [v, c] : E[u])
    if(v != par)
      dfs(v, u, c);
}

void build_lca(){
  for(int j=1; j<18; j++)
    for(int i=1; i<=n; i++)
      if(P[i][j-1] > 0){
        P[i][j] = P[P[i][j-1]][j-1];
        M[i][j] = max(M[i][j-1], M[P[i][j-1]][j-1]);
      }
}

int maxlca(int u, int v){
  int ret = 0;
  if(depth[u] < depth[v])
    swap(u, v);
  
  for(int i=17; i>=0; i--)
    if(depth[u] - (1<<i) >= depth[v]){
      ret = max(ret, M[u][i]);
      u = P[u][i];
    }
  
  if(u == v) return ret;
  
  for(int i=17; i>=0; i--)
    if(P[u][i] != P[v][i]){
      ret = max(ret, max(M[u][i], M[v][i]));
      u = P[u][i], v = P[v][i];
    }
  
  return ret = max(ret, max(M[u][0], M[v][0]));
}

void build_sparse_table(){
  for(int i=1; i<n; i++)
    st[i][0] = maxlca(i, i+1); //between nodes i and i+1
  
  for(int j=1; j<18; j++)
    for(int i=1; i+(1<<j)<=n; i++)
      st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
}

void solve(){
  scanf("%d%d%d", &n, &m, &q);
  for(int i=1; i<=n; i++){
    anc[i] = i;
    E[i].clear();
    depth[i] = 0;
    for(int j=0; j<18; j++)
      P[i][j] = M[i][j] = 0;
  }
  for(int i=1; i<=m; i++){
    int a, b; scanf("%d%d", &a, &b);
    if(find(a) != find(b)){
      E[a].push_back({b, i});
      E[b].push_back({a, i});
      anc[find(b)] = find(a);
    }
  }
  
  dfs(1, 0, 0);
  build_lca();
  build_sparse_table();
  
  vector<int> lg(n+1);
  int currentLog = 0;
  for(int i=1; i<=n; i++){
    if(i == (1<<(currentLog+1)))
      currentLog++;
    lg[i] = currentLog;
  }
  
  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    if(l == r){
      printf("0 ");
      continue;
    }
    r--;
    int k = lg[r-l+1];
    int ans = max(st[l][k], st[r-(1<<k)+1][k]);
    printf("%d ", ans);
  }
  puts("");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
