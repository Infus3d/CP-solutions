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
  int n; scanf("%d", &n);
  vector<long long> a(n);
  for(int i=0; i<n; i++){
    scanf("%lld", &a[i]);
    if(i > 0) a[i] += a[i-1];
  }
  int sq = sqrt(2*n);
  vector<vector<long long>> dp(n+1, vector<long long>(sq+1, -1));
  dp[n][0] = (long long)1e16;
  for(int i=n-1; i>=0; i--){
    for(int j=i; j<min(n, i+sq); j++){
      long long sum = a[j] - (i > 0 ? a[i-1] : 0);
      if(dp[j+1][j-i] != -1 && sum < dp[j+1][j-i] && dp[i][j-i+1] < sum)
        dp[i][j-i+1] = sum;
    }
    for(int j=0; j<=sq; j++)
      umax(dp[i][j], dp[i+1][j]);
  }
  for(int i=sq; i>=1; i--){
    if(dp[0][i] != -1){
      printf("%d\n", i);
      return;
    }
  }
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
