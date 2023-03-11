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
  vector<int> a(n+1, 0);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  vector<vector<int>> dp(n+1, vector<int>(1001, 1000001));
  vector<vector<int>> track(n+1, vector<int>(1001, 0));
  dp[0][0] = 0;
  
  for(int i=1; i<=n; i++){
    for(int j=0; j<=1000; j++){
      int adding = j - a[i];
      if(adding >= 0 && max(j, dp[i-1][adding]) < dp[i][j]){
        dp[i][j] = max(j, dp[i-1][adding]);
        track[i][j] = -1;
      }
      
      int subbing = j + a[i];
      if(subbing <= 1000 && max(j, dp[i-1][subbing]) < dp[i][j]){
        dp[i][j] = max(j, dp[i-1][subbing]);
        track[i][j] = 1;
      }
    }
  }
  
  int idx = 0;
  if(dp[n][idx] == 1000001){
    puts("IMPOSSIBLE");
    return;
  }
  
  
  int cur = n;
  vector<char> ans;
  while(cur > 0){
    if(track[cur][idx] > 0){
      ans.push_back('D');
    } else {
      ans.push_back('U');
    }
    idx += track[cur][idx] * a[cur];
    cur--;
  }
  
  reverse(all(ans));
  for(char c : ans){
    printf("%c", c);
  }
  puts("");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
