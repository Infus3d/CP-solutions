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

int n, d[N], exort[N], ans;
vector<int> E[N];
set<int> setik[N];

void dfs(int u, int par){
  exort[u] = exort[par] ^ d[u];
  setik[u].insert(exort[u]);
  
  bool needToChange = false;
  for(int v : E[u]){
    if(v != par){
      dfs(v, u);
      if(setik[u].size() < setik[v].size())
        swap(setik[u], setik[v]);
      
      for(int j : setik[v])
        if(setik[u].find((j ^ d[u])) != setik[u].end())
          needToChange = true;
      
      for(int j : setik[v])
        setik[u].insert(j);
      
      setik[v].clear();
    }
  }
  if(needToChange){
    ans++;
    setik[u].clear(); //paths going to any node below u will have non-zero xor
  }
}

void solve(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d", &d[i]);
  for(int i=1; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    E[a].push_back(b);
    E[b].push_back(a);
  }
  
  dfs(1, 0);
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
