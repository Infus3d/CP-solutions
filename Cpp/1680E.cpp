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

char s[2][N];
int dp[2][N];

void solve(){
  int n; scanf("%d", &n);
  int st = n, en = 0;
  for(int i=0; i<2; i++){
    scanf("%s", s[i]);
    for(int j=0; j<n; j++)
      if(s[i][j] == '*'){
        st = min(st, j);
        en = max(en, j);
        dp[i][j] = MOD;
      }
  }
  
  dp[0][st] = (s[1][st] == '*');
  dp[1][st] = (s[0][st] == '*');
  for(int i=st+1; i<=en; i++){
    dp[0][i] = min(dp[0][i-1]+1+(s[1][i] == '*'), dp[1][i-1]+2);
    dp[1][i] = min(dp[1][i-1]+1+(s[0][i] == '*'), dp[0][i-1]+2);
  }
  printf("%d\n", min(dp[0][en], dp[1][en]));
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
