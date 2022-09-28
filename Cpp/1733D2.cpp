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
const int K = 5e3+3;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m, x, y, v[N];
long long dp[N][N];
char s[N], t[N];

long long ycost(int l, int r){
  if(v[l]+1 == v[r]) return x;
  return y;
}

long long xcost(int l, int r){
  return 1ll * (v[r] - v[l]) * x;
}

long long rec(int l, int r){
  //~ printf("%d %d\n", l, r);
  if(r < l) return 0LL;
  long long &ret = dp[l][r];
  if(~ret) return ret;
  ret = (long long)1e18;
  umin(ret, rec(l+1, r-1) + ycost(l, r));
  umin(ret, rec(l+2, r) + xcost(l, l+1));
  umin(ret, rec(l, r-2) + xcost(r-1, r));
  return ret;
}

void solve(){
  scanf("%d%d%d", &n, &x, &y);
  scanf("%s%s", s, t);
  m = 0;
  for(int i=0; i<n; i++){
    if(s[i] != t[i]){
      v[m++] = i;
    }
  }
  if(m % 2 == 1){
    puts("-1");
    return;
  }
  if(y <= x){
    if(m == 2 && v[0]+1 == v[1])
      printf("%d\n", min(x, y*2));
    else
      printf("%lld\n", 1LL * (m/2) * y);
  } else {
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++)
        dp[i][j] = -1;
    }
    //~ puts("****");
    printf("%lld\n", rec(0, m-1));
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
