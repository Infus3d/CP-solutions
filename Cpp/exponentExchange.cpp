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
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int dp[2][2][N];

void solve(){
  int b, p;
  scanf("%d%d", &b, &p);
  vector<int> a(p);
  for(int i=0; i<p; i++){
    scanf("%d", &a[i]);
  }
  reverse(all(a));
  
  int m = b * p;
  for(int i=0; i<=m; i++){
    for(int j=0; j<2; j++){
      for(int k=0; k<2; k++){
        dp[j][k][i] = MOD;
      }
    }
  }
  
  dp[0][0][0] = b - a[0];
  dp[0][1][a[0]] = 0;
  
  for(int i=1; i<p; i++){
    for(int k=0; k<=m; k++){
      dp[1][0][k] = min(dp[1][0][k], dp[0][0][k] + (b - a[i] - 1));
      dp[1][0][k] = min(dp[1][0][k], dp[0][1][k] + (b - a[i]));
      
      if(k >= a[i]+1) dp[1][1][k] = min(dp[1][1][k], dp[0][0][k - a[i] - 1]);
      if(k >= a[i]) dp[1][1][k] = min(dp[1][1][k], dp[0][1][k - a[i]]);
    }
    for(int k=0; k<=m; k++){            //just get ready for i+1
      dp[0][0][k] = dp[1][0][k];
      dp[0][1][k] = dp[1][1][k];
      dp[1][0][k] = dp[1][1][k] = MOD;
    }
  }
  
  int ans = MOD;
  for(int i=0; i<=m; i++){
    ans = min(ans, max(dp[0][0][i], i));
    ans = min(ans, max(dp[0][1][i], i));
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
