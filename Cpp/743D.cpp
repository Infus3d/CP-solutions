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
const int MOD = 1e9+7;
const ll INF = 1e18;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, a, b;
ll d[N], f[N], ans = -INF;
vector<int> E[N];
bool exist = false;

void dfs(int x, int y){
  f[x] = -INF;
  ll mx1 = -INF, mx2 = -INF;
  for(int i : E[x])
    if(i ^ y){
      dfs(i, x);
      d[x] += d[i];
      f[x] = max(f[x], f[i]);
      if(f[i] >= mx1)
        mx2 = mx1, mx1 = f[i];
      else if(f[i] > mx2)
        mx2 = f[i];
    }
  f[x] = max(f[x], d[x]);
  
  if(mx1 != -INF && mx2 != -INF){
    exist = true;
    ans = max(ans, mx1 + mx2);
  }
}

void solve(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%lld", &d[i]);
  for(int i=1; i<n; i++){
    scanf("%d%d", &a, &b);
    E[a].pb(b);
    E[b].pb(a);
  }
  
  exist = false; ans = -INF;
  dfs(1, 0);
  
  if(exist)
    printf("%lld\n", ans);
  else
    printf("Impossible\n");
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
