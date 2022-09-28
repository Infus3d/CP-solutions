#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
//~ #define db puts("*****")
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

int n, a, b, da, db;
int vis[4][N], diam[2][N];
vector<int> E[N];

void dfs(int x, int par, int maxJump, int t){
  if(vis[t][x] >= maxJump) return;
  for(int i : E[x]){
    if(i != par){
      vis[t][i] = vis[t][x] + 1;
      dfs(i, x, maxJump, t);
    }
  }
}

void dfsDiam(int x, int par, int t){
  for(int i : E[x]){
    if(i != par){
      diam[t][i] = diam[t][x] + 1;
      dfsDiam(i, x, t);
    }
  }
}

void solve(){
  scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
  for(int i=1; i<=n; i++){
    E[i].clear();
    vis[0][i] = vis[1][i] = -1;
    vis[2][i] = vis[3][i] = 0;
    diam[0][i] = diam[1][i] = 0;
  }
  for(int i=0; i<n-1; i++){
    int x, y;
    scanf("%d%d", &x, &y);
    E[x].push_back(y);
    E[y].push_back(x);
  }
  if(da*2+1 > db){
    puts("Alice");
    return;
  }
  vis[0][a] = vis[1][b] = 0;
  dfs(a, 0, da, 0);
  dfs(b, 0, db, 1);
  dfsDiam(1, 0, 0);
  int maxi1 = 0, root1 = -1;
  for(int i=1; i<=n; i++){
    if(maxi1 < diam[0][i]){
      maxi1 = diam[0][i];
      root1 = i;
    }
  }
  dfsDiam(root1, 0, 1);
  int maxi2 = 0, root2 = -1;
  for(int i=1; i<=n; i++){
    if(maxi2 < diam[1][i]){
      maxi2 = diam[1][i];
      root2 = i;
    }
  }
  assert(root1 != -1 && root2 != -1);
  dfs(root1, 0, n-1, 2);
  dfs(root2, 0, n-1, 3);
  if(vis[0][b] != -1){
    puts("Alice");
    return;
  }
  for(int i=1; i<=n; i++){
    if(vis[0][i] == -1 && vis[1][i] != -1 && max(vis[2][i], vis[3][i]) >= da*2+1){
      puts("Bob");
      return;
    }
  }
  puts("Alice");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
