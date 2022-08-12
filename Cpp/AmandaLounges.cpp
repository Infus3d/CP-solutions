#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
#define all(x)  x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m, d[N][2], cnt[2];
vector<int> E[N];
bool impos = false;

void dfs(int x, int parity, int t){
  d[x][t] = parity;
  cnt[t] += parity;
  for(int i : E[x]){
    if(d[i][t] == -1)
      dfs(i, parity^1, t);
    else if(d[i][t] != (parity^1)){
      impos = true;
      break;
    }
  }
}

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++) d[i][0] = d[i][1] = -1;
  for(int i=1; i<=m; i++){
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    if(c == 1){
      E[a].pb(b);
      E[b].pb(a);
    }
    else{
      int parity = (!c ? 0 : 1);
      if(d[a][0] == (parity^1) || d[b][0] == (parity^1))
        impos = true;
      d[a][0] = d[b][0] = parity;
      d[a][1] = d[b][1] = parity;
    }
  }
  
  int ans = 0;
  for(int i=1; i<=n; i++)
    if(d[i][0] != -1)
      dfs(i, d[i][0], 0);
  
  for(int i=1; i<=n; i++)
    if(d[i][0] == 1)
      ans++;
  
  for(int i=1; i<=n; i++)
    if(d[i][0] == -1 && sz(E[i]) > 0){
      cnt[0] = cnt[1] = 0;
      dfs(i, 0, 0);
      dfs(i, 1, 1);
      ans += min(cnt[0], cnt[1]);
    }
  
  if(impos) printf("impossible\n");
  else printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
