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
const int K = 5e2+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, m, a, b;
int deg[N], id[N], edge[K][K], vis[N];
vector<int> E[N];
vector<int> heavy, light;
set<int> setik[N];

ll ans, cyc[2][2][2];
ll nCr[N][4];
 
void precalc(){
  nCr[0][0] = 1;
  for(int i=1; i<=n; i++){
    nCr[i][0] = 1;
    if(i < 4) nCr[i][i] = 1;
    for(int j=1; j<min(i, 4); j++)
      nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
  }
}
 
ll C(int nn, int kk){
  if(nn < kk) return 0LL;
  if(nn < 0 || kk < 0) return 0LL;
  return nCr[nn][kk];
}

ll getVal(int x, int y, int z){
  ll ret = 2LL*C(deg[x]-2, 2) + 2LL*C(deg[y]-2, 2) + 2LL*C(deg[z]-2, 2);
  return ret;
}

void three_cycle_calc(){
  memset(cyc, 0, sizeof(cyc));
  int blok = sqrt(m);
  
  for(int i=1; i<=n; i++){
    if(deg[i] < blok) light.pb(i);
    else heavy.pb(i);
  }
  for(int i=0; i<sz(heavy); i++) id[heavy[i]] = i;
  for(int i=0; i<sz(heavy); i++)
    for(int j : E[heavy[i]])
      if(deg[j] >= blok){
        edge[i][id[j]] = 1;
      }
  
  for(int i=0; i<sz(heavy); i++)
    for(int j=i+1; j<sz(heavy); j++)
      for(int k=j+1; k<sz(heavy); k++)
        if(edge[i][j] && edge[j][k] && edge[k][i]){
          ll val = getVal(heavy[i], heavy[j], heavy[k]);
          ans -= val;  //3-heavy-cycle contribution
        }
  
  for(int i=1; i<=n; i++)
    for(int j : E[i])
      setik[i].insert(j);
  
  for(int v : light){
    int len = sz(E[v]);
    for(int i=0; i<len; i++){
      for(int j=i+1; j<len; j++){
        vector<int> c;
        c.pb(0);
        c.pb((deg[E[v][i]] < blok ? 0 : 1));
        c.pb(deg[E[v][j]] < blok ? 0 : 1);
        sort(all(c));
        
        if(setik[E[v][i]].find(E[v][j]) != setik[E[v][i]].end()){
          ll val = getVal(v, E[v][i], E[v][j]);
          cyc[c[0]][c[1]][c[2]] += val; //all other 3-cycle contributions
        }
      }
    }
  }
  
  ans -= cyc[0][0][0] / 3; //all three light nodes
  ans -= cyc[0][0][1] / 2; //2 light, 1 heavy
  ans -= cyc[0][1][1] / 1; //1 light, 2 heavy
}

void dfs(int x){
  vis[x] = 1;
  for(int i : E[x]){
    ans += 1LL * C(deg[x]-1, 3) * (deg[i]-1);
    if(!vis[i])
      dfs(i);
  }
}

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=m; i++){
    scanf("%d%d", &a, &b);
    E[a].pb(b);
    E[b].pb(a);
    deg[a]++; deg[b]++;
  }
  
  precalc();
  three_cycle_calc();
  
  for(int i=1; i<=n; i++)
    if(!vis[i])
      dfs(i);  //there are multiple connected graphs
  
  printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}

/*
10 11
1 2
2 3
3 1
3 4
4 1
1 5
1 6
1 7
3 8
3 9
3 10

Ans: 92
*/
