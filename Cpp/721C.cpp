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

const int N = 5e3+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, m, t, path[N][N];
vector<pair<int, int>> E[N];
int dp[N][N];



void solve(){
  scanf("%d%d%d", &n, &m, &t);
  for(int i=1; i<=m; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    E[a].pb({b, c});
  }
  
  memset(dp, -1, sizeof(dp));
  dp[1][1] = 0; 
  queue<pii> Q;
  Q.push({1, 1});
  while(!Q.empty()){
    pii tr = Q.front(); Q.pop();
    for(pii i : E[tr.ff])
      if(dp[tr.ff][tr.ss] + i.ss <= t && (dp[i.ff][tr.ss+1] == -1 || dp[i.ff][tr.ss+1] > dp[tr.ff][tr.ss] + i.ss)){
        dp[i.ff][tr.ss+1] = dp[tr.ff][tr.ss] + i.ss;
        path[i.ff][tr.ss+1] = tr.ff;
        Q.push({i.ff, tr.ss+1});
      }
  }
  
  for(int i=n; i>=1; i--)
    if(~dp[n][i] && dp[n][i] <= t){
      printf("%d\n", i);
      int a = n, b = i;
      
      vector<int> ans;
      while(b > 0){
        ans.pb(a);
        a = path[a][b];
        b--;
      }
      reverse(all(ans));
      for(int j : ans)
        printf("%d ", j);
      puts("");
      return;
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
