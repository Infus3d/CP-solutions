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

const int N = 3e3+2;
const int K = 1e4;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, dp[2][2*K+5];
char s[N];

int add(int x, int y){
  return (x + y) % MOD;
}

void solve(){
  scanf("%d", &n);
  scanf("%s", s+1);
  
  dp[0][K] = 1;
  for(int i=1; i<=n; i++){
    for(int j=0; j<=2*K; j++){
      if(s[i] == 'A'){
        dp[1][j] = add(dp[1][j], dp[0][j]);
        dp[1][j] = add(dp[1][j], dp[0][j]);
        if(j < 2*K-2) dp[1][j] = add(dp[1][j], dp[0][j+3]);
      }
      else if(s[i] == 'F'){
        dp[1][j] = add(dp[1][j], dp[0][j]);
      }
      else{
        if(j > 2) dp[1][j] = add(dp[1][j], dp[0][j-3]);
        if(j < 2*K-2) dp[1][j] = add(dp[1][j], dp[0][j+3]);
        dp[1][j] = add(dp[1][j], dp[0][j]);
      }
    }
    for(int j=0; j<=2*K; j++){
      dp[0][j] = dp[1][j];
      dp[1][j] = 0;
    }
  }
  int ans = 0;
  for(int i=K+1; i<=2*K; i++)
    ans = add(ans, dp[0][i]);
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
