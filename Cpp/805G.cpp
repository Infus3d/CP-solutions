#include "bits/stdc++.h"

using namespace std;

const int N = 2e5+1;

int n, q, lvl[N], P[N][18];
vector<int> E[N];

void dfs(int u, int par){
  lvl[u] = lvl[par]+1;
  P[u][0] = par;
  for(int v : E[u])
    if(v != par)
      dfs(v, u);
}

void build_lca(){
  for(int j=1; j<18; j++)
    for(int i=1; i<=n; i++)
      P[i][j] = P[P[i][j-1]][j-1];
}

int lca(int u, int v){
  if(lvl[u] < lvl[v])
    swap(u, v);
  
  for(int i=17; i>=0; i--)
    if(lvl[u] - (1<<i) >= lvl[v])
      u = P[u][i];
  
  if(u == v) return u;
  
  for(int i=17; i>=0; i--)
    if(P[u][i] != P[v][i])
      u = P[u][i], v = P[v][i];
  
  return P[u][0];
}

int main(){
  scanf("%d", &n);
  for(int i=1; i<n; i++){
    int a, b; scanf("%d%d", &a, &b);
    E[a].push_back(b);
    E[b].push_back(a);
  }
  
  dfs(1, 0);
  build_lca();
  
  scanf("%d", &q);
  while(q--){
    int k; scanf("%d", &k);
    vector<int> a(k);
    for(int i=0; i<k; i++)
      scanf("%d", &a[i]);
    
    sort(a.begin(), a.end(), [&](int x, int y){
      return lvl[x] > lvl[y];
    });
    
    int node1 = a[0], node2 = -1;
    vector<bool> marked(k);
    for(int i=0; i<k; i++){
      if(lca(node1, a[i]) == a[i])
        marked[i] = true;
      else if(node2 == -1)
        node2 = a[i];
    }
    
    if(node2 == -1){
      puts("YES");
      continue;
    }
    
    for(int i=0; i<k; i++)
      if(!marked[i] && lca(node2, a[i]) == a[i])
        marked[i] = true;
    
    bool ans = true;
    for(auto i : marked)
      ans &= i;
    
    ans &= (lvl[lca(node1, node2)] <= lvl[a.back()]);
    printf("%s\n", (ans == true ? "YES" : "NO"));
  }
  
  return 0;
}
