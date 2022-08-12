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
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 52;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m;
char s[N][N];
double dp[N][N];

bool ok(int x1, int y1, int x2, int y2){
  int x = x1, y = y1;
  while(x < x2 || y < y2){
    if(s[x][y] == '#') return false;
    int diag = (x-x1+1)*(y2-y1) - (y-y1+1)*(x2-x1);
    if(diag <= 0) x++;
    if(diag >= 0) y++;
  }
  return true;
}

double dist(int x1, int y1, int x2, int y2){
  return sqrt(sqr(y2-y1) + sqr(x2-x1));
}

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++)
    scanf("%s", s[i]);
  
  for(int i=0; i<=n; i++)
    for(int j=0; j<=m; j++)
      dp[i][j] = 1000.0;
  
  dp[0][0] = 0.0;
  for(int i=0; i<=n; i++){
    for(int j=0; j<=m; j++){
      for(int u=i+1; u<=n; u++){
        for(int v=j+1; v<=m; v++){
          if(ok(i, j, u, v)){
            umin(dp[u][v], dp[i][j] + dist(i, j, u, v));
          }
        }
      }
      for(int u=i; u<=n; u++)
        umin(dp[u][j], dp[i][j] + (u-i));
      for(int v=j; v<=m; v++)
        umin(dp[i][v], dp[i][j] + (v-j));
    }
  }
  
  printf("%.9lf\n", dp[n][m]);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
