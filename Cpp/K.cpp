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

const int N = 2502;
const int K = 1e3+2;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int dp[N][N], n, k, a;
vector<int> E[N];

int add(int x, int y){
  return (x + y) % MOD;
}

int mul(int x, int y){
  return (1LL * x * y) % MOD;
}

void dfs(int x){
  for(int i : E[x]){
    dfs(i);
    vector<int> inner(k+1, 0);
    for(int j=1; j<=k; j++)
      inner[j] = mul(dp[i][j], (j-1));
    for(int j=2; j<=k; j++)
      inner[j] = add(inner[j], mul(dp[i][j-1], (k-j+1)));
    for(int j=1; j<=k; j++)
      dp[x][j] = mul(dp[x][j] == 0 ? 1 : dp[x][j], inner[j]);
  }
  if(sz(E[x]) == 0)
    dp[x][1] = k;
}

void solve(){
  scanf("%d%d", &n, &k);
  for(int i=2; i<=n; i++){
    scanf("%d", &a); a++;
    E[a].pb(i);
  }
  dfs(1);
  printf("%d\n", dp[1][k]);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
