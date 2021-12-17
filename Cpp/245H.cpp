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
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, q, dp[N][N], isPali[N][N];
char s[N];
int a, b;

int rec(int x, int y){
  if(x > y){
    isPali[x][y] = 1;
    return dp[x][y] = 0;
  }
  if(x == y)
    return dp[x][y] = isPali[x][y] = 1;
  
  int &ret = dp[x][y];
  if(~ret) 
    return ret;
  
  ret = rec(x, y-1) + rec(x+1, y) - rec(x+1, y-1);
  if(s[x] == s[y])  
    isPali[x][y] |= isPali[x+1][y-1];
  else 
    isPali[x][y] = 0;
  ret += isPali[x][y];
  
  return ret;
}

void solve(){
  scanf("%s", s); n = strlen(s);
  scanf("%d", &q);
  
  memset(dp, -1, sizeof dp);
  
  rec(0, n-1);
  while(q--){
    scanf("%d%d", &a, &b);
    a--, b--;
    printf("%d\n", dp[a][b]);
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
