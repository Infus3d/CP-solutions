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

int n, m, q, ten[N], d[N];
vector<int> E[N];
int lvl[N], P[N][19]; //needed for lca
int upward[N][19], downward[N][19];

int mul(int x, int y){
  return (1LL * x * y) % m;
}

int add(int x, int y){
  return (x + y) % m;
}

void dfs(int x, int par){
  upward[x][0] = d[x];
  downward[x][0] = d[x];
  P[x][0] = par; //0th parent of x is par
  lvl[x] = lvl[par]+1;
  
  for(int i : E[x])
    if(i != par)
      dfs(i, x);
}

void build_lca(){
  for(int j=1; j<19; j++)
    for(int i=1; i<=n; i++)
      if(P[i][j-1] > 0){
        upward[i][j] = mul(upward[i][j-1], ten[(1<<(j-1))]);
        upward[i][j] = add(upward[i][j], upward[P[i][j-1]][j-1]);
        
        downward[i][j] = mul(downward[P[i][j-1]][j-1], ten[(1<<(j-1))]);
        downward[i][j] = add(downward[i][j], downward[i][j-1]);
        
        P[i][j] = P[P[i][j-1]][j-1];
      }
}

int lca(int x, int y){
  if(lvl[x] < lvl[y]) 
    swap(x, y);
  
  for(int i=18; i>=0; i--)
    if(lvl[x] - (1<<i) >= lvl[y])
      x = P[x][i];
    
  if(x == y) return x;
  
  for(int i=18; i>=0; i--)
    if(P[x][i] > 0 && P[x][i] != P[y][i])
      x = P[x][i], y = P[y][i];
  
  return P[x][0];
}

int jump_upward(int x, int par){
  int cur = 0;
  for(int i=18; i>=0; i--)
    if(lvl[x] - (1<<i) >= lvl[par]){
      cur = mul(cur, ten[(1<<i)]);
      cur = add(cur, upward[x][i]);
      x = P[x][i];
    }
  return cur;
}

int jump_downward(int x, int par){ //still technically jumps 'upward' direction, but simulates the 'downward' jump
  int cur = 0, sofar = 0;
  for(int i=18; i>=0; i--)
    if(lvl[x] - (1<<i) >= lvl[par]){
      int temp = mul(downward[x][i], ten[sofar]);
      cur = add(cur, temp);
      sofar += (1<<i);  
      x = P[x][i];
    }
  return cur;
}

void solve(){
  scanf("%d%d%d", &n, &m, &q);
  for(int i=1; i<n; i++){
    int a, b; scanf("%d%d", &a, &b);
    E[a].pb(b), E[b].pb(a);
  }
  
  ten[0] = 1 % m;
  for(int i=1; i<=n; i++){
    scanf("%d", &d[i]);
    ten[i] = mul(ten[i-1], 10);
  }
  dfs(1, 0);
  build_lca();
  
  while(q--){
    int a, b; 
    scanf("%d%d", &a, &b);
    
    int el_see_a = lca(a, b);
    int fhalf = jump_upward(a, el_see_a);
    int shalf = jump_downward(b, el_see_a);
    
    int ans = add(mul(fhalf, 10), d[el_see_a]);
    ans = add(mul(ans, ten[lvl[b]-lvl[el_see_a]]), shalf);
    
    printf("%d\n", ans);
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
