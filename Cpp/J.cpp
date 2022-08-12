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

const int N = 1050;
const int K = 1e3+2;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m, a[N], b[N], c[N], dp[N][N];

int add(int x, int y){
  return (x + y) % MOD;
}

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);
  for(int i=1; i<=m; i++) scanf("%d", &b[i]), c[b[i]] = 1;
  
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for(int i=1; i<=n; i++){
    for(int j=0; j<=(int)1023; j++){
      dp[i][j] = add(dp[i][j], dp[i-1][j]);
      dp[i][j^a[i]] = add(dp[i][j^a[i]], dp[i-1][j]);
    }
  }
  
  int ans = 0;
  for(int i=0; i<=(int)1023; i++){
    if(c[i] == 1)
      ans = add(ans, dp[n][i]);
    c[i] = 0;
  }
  
  int pw = 1;
  for(int i=1; i<=n; i++) pw = (pw * 2) % MOD;
  printf("%d\n", (int)((0LL + pw - ans + MOD + MOD) % MOD));
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int t=1; t<=testcase; t++){
    printf("Case %d: ", t);
    solve();
  }
  return 0;
}
