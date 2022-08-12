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

int n, m, a[N], b[N];
int d[1002][102];
ll dp[1002][2];

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++){
    a[i] = (int)1e9+7, b[i] = 0;
    for(int j=1; j<=m; j++){
      scanf("%d", &d[i][j]);
      a[i] = min(a[i], d[i][j]);
      b[i] = max(b[i], d[i][j]);
    }
  }
  
  for(int i=0; i<=n; i++)
    for(int j=0; j<2; j++)
      dp[i][j] = (ll)(1e13);
  
  dp[0][0] = 0;
  for(int i=1; i<=n; i++){
    dp[i][0] = min(dp[i][0], dp[i-1][0] + (abs(a[i-1] - b[i]) + (b[i] - a[i])));
    dp[i][0] = min(dp[i][0], dp[i-1][1] + (abs(b[i-1] - b[i]) + (b[i] - a[i])));
    
    dp[i][1] = min(dp[i][1], dp[i-1][0] + (abs(a[i-1] - a[i]) + (b[i] - a[i])));
    dp[i][1] = min(dp[i][1], dp[i-1][1] + (abs(b[i-1] - a[i]) + (b[i] - a[i])));
  }
  
  printf("%lld\n", min(dp[n][0], dp[n][1]));
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int i=1; i<=testcase; i++){
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}
