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

const int N = 2e2+2;
const int K = 1e3+2;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, k;
int d[N], dp[N][N][K];

void add(int &x, int y){
  x = (x + y) % MOD;
}

int mul(int x, int y){
  return (1LL * x * y) % MOD;
}

void solve(){
  scanf("%d%d", &n, &k);
  for(int i=1; i<=n; i++) scanf("%d", &d[i]);
  sort(d+1, d+n+1);
  
  dp[0][0][0] = 1;
  for(int i=1; i<=n; i++){
    for(int j=0; j<=n; j++){
      for(int v=0; v<=k; v++){
        int newV = v + j*(d[i] - d[i-1]);
        if(newV > k) continue;
        
        add(dp[i][j][newV], dp[i-1][j][v]); // open, place d[i] and close {1, 1}
        add(dp[i][j][newV], mul(j, dp[i-1][j][v])); // add d[i] to one of the open sets  {0, 0}
        if(j < n) add(dp[i][j+1][newV], dp[i-1][j][v]);  // open a new set and add d[i] {1, 0}
        if(j > 0) add(dp[i][j-1][newV], mul(j, dp[i-1][j][v]));  // add d[i] and close an open set {0, 1}
      }
    }
  }
  
  int ans = 0;
  for(int v=0; v<=k; v++)
    add(ans, dp[n][0][v]);
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
