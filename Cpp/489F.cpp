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

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m, mod, C[N][N];
char s[N];

int add(int x, int y){
  return (x + y) % mod;
}

int mul(int x, int y){
  return (1LL * x * y) % mod;
}

int rec(int zer, int one, vector<vector<int>> &dp){
  if(zer == 0 || one == 0) return 1;
  if(zer < 0 || one < 0) return 0;
  
  int &ret = dp[zer][one];
  if(~ret) return ret;
  
  ret = 0;
  ret = add(ret, mul(rec(zer-1, one, dp), mul(C[zer][1], C[one][1])));
  ret = add(ret, mul(rec(zer-2, one+2, dp), C[zer][2]));
  ret = add(ret, mul(rec(zer, one-2, dp), C[one][2]));
  return ret;
}

void solve(){
  scanf("%d%d%d", &n, &m, &mod);
  
  C[0][0] = 1;
  for(int i=1; i<=n; i++){
    C[i][0] = C[i][i] = 1;
    for(int j=1; j<i; j++)
      C[i][j] = add(C[i-1][j-1], C[i-1][j]);
  }
  
  vector<int> c(n+1);
  for(int i=1; i<=m; i++){
    scanf("%s", s);
    for(int j=0; j<n; j++)
      c[j] += s[j]-'0';
  }
  
  int zer = 0, one = 0;
  for(int i=0; i<n; i++){
    assert(c[i] < 3);
    if(c[i] == 0) zer++;
    if(c[i] == 1) one++;
  }
  
  vector<vector<int>> dp(zer+1, vector<int> (one+1, -1));
  printf("%d\n", rec(zer, one, dp));
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
