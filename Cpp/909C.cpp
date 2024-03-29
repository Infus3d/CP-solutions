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
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int dp[N][N], n;
char s[N];

int add(int x, int y){
  return (x + y) % MOD;
}

void solve(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf(" %c", &s[i]);
  
  dp[1][0] = 1;
  for(int i=2; i<=n; i++){
    int cur = 0;
    for(int j=n; j>=0; j--){
      cur = add(cur, dp[i-1][j]);
      if(s[i-1] == 'f')
        dp[i][j+1] = dp[i-1][j];
      else
        dp[i][j] = cur;
    }
  }

  int ans = 0;
  for(int i=0; i<=n; i++)
    ans = add(ans, dp[n][i]);
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
