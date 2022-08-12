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

void solve(){
  int n, m, cnt = 0;
  string s;
  map<string, int> mk;
  cin >> n;
  for(int i=1; i<=n; i++){
    getline(cin, s);
    mk[s] = cnt++;
  }
  
  int ans = MOD;
  int dp[2][102];
  for(int i=0; i<=100; i++) dp[0][i] = dp[1][i] = MOD;
  cin >> m;
  dp[1][0] = 0;
  for(int i=1; i<=m; i++){
    getline(cin, s);
    int bit = i%2;
    int a = mk[s];
    for(int j=0; j<cnt; j++){
      if(j != a) dp[bit][j] = min(dp[bit][j], min(dp[bit^1][a]+1, dp[bit^1][j]));
    }
    for(int j=0; j<cnt; j++) dp[bit^1][j] = MOD;
  }
  for(int i=0; i<cnt; i++) ans = min(ans, dp[m%2][i]);
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  cin >> testcase;
  for(int i=1; i<=testcase; i++){
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}
