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

const int N = 502;
const int K = 22;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, -1, 0, +1};

int n, m, k;
int dp[N][N][K];
int v[N], h[N], w[N][N][4];

int rec(int x, int y, int z){
  if(x < 1 || x > n) return MOD;
  if(y < 1 || y > m) return MOD;
  if(!z) return 0;
  
  int &ret = dp[x][y][z];
  if(~ret) return ret;
  
  ret = MOD;
  for(int i=0; i<4; i++)
    umin(ret, rec(x+dx[i], y+dy[i], z-1) + w[x][y][i]);
  
  return ret;
}

void solve(){
  scanf("%d%d%d", &n, &m, &k);
  for(int i=1; i<=n; i++)
    for(int j=1; j<m; j++){
      scanf("%d", &h[j]);
      w[i][j+1][1] = w[i][j][3] = h[j];
    }
  
  for(int i=1; i<n; i++)
    for(int j=1; j<=m; j++){
      scanf("%d", &v[j]);
      w[i][j][2] = w[i+1][j][0] = v[j];
    }
  
  memset(dp, -1, sizeof(dp));
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      printf("%d%c", (k%2 ? -1 : rec(i, j, k/2) * 2), (j == m ? '\n' : ' '));
}

int main(){
  int testcase = 1;
  while(testcase--){
    solve();
  }
  return 0;
}
