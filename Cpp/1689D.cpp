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

const int N = 1e3+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

char s[N][N];
int dp[N][N][4];

void solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; ++i){
    scanf("%s", s[i]);
    for(int j=0; j<m; j++){
      int a = (s[i][j] == 'B');
      dp[i][j][0] = dp[i][j][1] = a;
      dp[i][j][2] = dp[i][j][3] = a;
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(i > 0 && dp[i-1][j][0] != 0)
        umax(dp[i][j][0], dp[i-1][j][0]+1);
      if(j > 0 && dp[i][j-1][0] != 0)
        umax(dp[i][j][0], dp[i][j-1][0]+1);
    }
  }
  for(int i=0; i<n; i++){
    for(int j=m-1; j>=0; j--){
      if(i > 0 && dp[i-1][j][1] != 0)
        umax(dp[i][j][1], dp[i-1][j][1]+1);
      if(j < m-1 && dp[i][j+1][1] != 0)
        umax(dp[i][j][1], dp[i][j+1][1]+1);
    }
  }
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<m; j++){
      if(i < n-1 && dp[i+1][j][2] != 0)
        umax(dp[i][j][2], dp[i+1][j][2]+1);
      if(j > 0 && dp[i][j-1][2] != 0)
        umax(dp[i][j][2], dp[i][j-1][2]+1);
    }
  }
  for(int i=n-1; i>=0; i--){
    for(int j=m-1; j>=0; j--){
      if(i < n-1 && dp[i+1][j][3] != 0)
        umax(dp[i][j][3], dp[i+1][j][3]+1);
      if(j < m-1 && dp[i][j+1][3] != 0)
        umax(dp[i][j][3], dp[i][j+1][3]+1);
    }
  }
  int x = -1, y = -1, mini = n+m+1;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int d = max(max(dp[i][j][0], dp[i][j][1]), max(dp[i][j][2], dp[i][j][3]));
      if(mini > d){
        mini = d;
        x = i, y = j;
      }
    }
  }
  printf("%d %d\n", x+1, y+1);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
