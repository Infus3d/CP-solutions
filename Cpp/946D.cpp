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

const int N = 5e2+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, m, k;
int dp[N][N], d[N][N], classes[N];
char s[N];

void solve(){
  scanf("%d%d%d", &n, &m, &k);
  for(int i=0; i<=n; i++)
    for(int j=0; j<=max(m, k); j++){
      dp[i][j] = MOD;
      d[i][j] = MOD;
    }
  
  for(int i=1; i<=n; i++){
    scanf("%s", s+1);
    for(int j=1; j<=m; j++){
      int p = j-1, c = 0;
      while(p <= m){
        umin(d[i][c], p-j+1); p++;
        c += (s[p] == '1' ? 1 : 0);
      }
    }
    int c = 0;
    for(int j=1; j<=m; j++) c += (s[j] == '1' ? 1 : 0);
    classes[i] = c;
  }
  
  dp[0][0] = 0;
  for(int i=1; i<=n; i++)
    for(int j=0; j<=k; j++)
      for(int attend=0; attend<=classes[i]; attend++)
        if(classes[i]-attend <= j)
          umin(dp[i][j], dp[i-1][j-(classes[i]-attend)] + d[i][attend]);
  
  int ans = MOD;
  for(int i=0; i<=k; i++)
    umin(ans, dp[n][i]);
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
