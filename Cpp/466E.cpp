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

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, m, cn, par[N], in[N], out[N], p[N];
vector<int> E[N], q[N];

struct query{
  int t, x, y;
} d[N];

int find(int x){
  if(p[x] == x) return x;
  else return p[x] = find(p[x]);
}

void dfs(int x, int y){
  in[x] = ++cn;
  for(int i : E[x])
    dfs(i, x);
  out[x] = cn;
}

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=m; i++){
    scanf("%d%d", &d[i].t, &d[i].x);
    if(d[i].t != 2) scanf("%d", &d[i].y);
    if(d[i].t == 1){
      par[d[i].x] = d[i].y;
      E[d[i].y].pb(d[i].x);
    }
    if(d[i].t == 3) q[d[i].y].pb(i);
  }
  
  for(int i=1; i<=n; i++){
    if(par[i] == 0)
      dfs(i, par[i]);
    p[i] = i;
  }
  
  int pcount = 0;
  for(int i=1; i<=m; i++){
    if(d[i].t == 1)
      p[find(d[i].x)] = find(d[i].y);
    else if(d[i].t == 2){
      pcount++;
      for(int j : q[pcount]){
        int x = d[j].x, y = d[i].x;
        if(find(x) == find(y) && in[x] <= in[y] && out[y] <= out[x])
          d[j].y = 1;  //YES
        else
          d[j].y = 0;  //NO
      }
    }
    else
      printf("%s\n", (d[i].y == 1 ? "YES" : "NO"));
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
