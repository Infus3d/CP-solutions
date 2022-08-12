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
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, vis[N];
ll val[N], minVal[N], sum[N];
vector<int> E[N];

void dfs(int x){
  vis[x] = 1;
  
  minVal[x] = MOD;
  for(int i : E[x]){
    dfs(i);
    minVal[x] = min(minVal[x], minVal[i]);
    sum[x] += sum[i];
  }
  
  if(minVal[x] == MOD)
    minVal[x] = sum[x] = val[x];
  else{
    sum[x] -= minVal[x];
    minVal[x] = max(minVal[x], val[x]);
    sum[x] += minVal[x];
  }
}

void solve(){
  scanf("%d", &n);
  for(int i=0; i<=n; i++){
    E[i].clear();
    vis[i] = val[i] = minVal[i] = sum[i] = 0;
  }
  for(int i=1; i<=n; i++){
    int a; scanf("%d", &a);
    val[i] = a;
  }
  for(int i=1; i<=n; i++){
    int a; scanf("%d", &a);
    E[a].pb(i);
  }
  
  ll ans = 0;
  for(int i=1; i<=n; i++)
    if(!vis[i]){
      dfs(i);
      ans += sum[i];
    }
  printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int tt=1; tt<=testcase; tt++){
    printf("Case #%d: ", tt);
    solve();
  }
  return 0;
}
