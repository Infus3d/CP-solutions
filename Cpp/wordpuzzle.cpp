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
const int K = 52;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

char s[2*N], t[K];
int dp[2*N][K], n, m;
map<vector<char>, int> vis;

int add(int x, int y){
  return (x+y) % MOD;
}

void solve(){
  scanf("%s%s", s+1, t+1);
  n = strlen(s+1);
  m = strlen(t+1);
  int ans = 0;
  for(int k=1; k<=m; k++){
    vector<char> rot;
    for(int i=k; i<=m; i++) rot.pb(t[i]);
    for(int i=1; i<k; i++) rot.pb(t[i]);
    if(vis.find(rot) != vis.end()) continue;
    vis[rot] = 1;
    
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
      for(int j=0; j<=m; j++)
        dp[i][j] = dp[i-1][j];
      for(int j=1; j<=m; j++){
        if(s[i] == rot[j-1])
          dp[i][j] = add(dp[i][j], dp[i-1][j-1]);
      }
    }
    ans = add(ans, dp[n][m]);
  }
  
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
