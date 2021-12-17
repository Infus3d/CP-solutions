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

const int N = 5e5+7;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, d[N], f[N], e[N], h[N], g[N];

int add(int x, int y){
  return (0LL + x + y + MOD) % MOD;
}

int mul(int x, int y){
  return (1LL * x * y) % MOD;
}

void solve(){
  f[0] = 1;
  int one = 0, zer = 0;
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &d[i]);
    f[i] = mul(f[i-1], 2);
    if(d[i] == 0) zer++;
    if(d[i] == 1) one++;
  }
  
  int ans = 0;
  for(int i=1; i<=n; i++){
    if(d[i] == 0)
      e[d[i]] = add(e[d[i]], add(e[d[i]], 1));
    if(d[i] > 0){
      ans = add(ans, add(e[d[i]], e[d[i]-1]));
      e[d[i]] = add(e[d[i]], add(e[d[i]], e[d[i]-1]));
    }
    if(d[i] > 1){
      ans = add(ans, add(h[d[i]], e[d[i]-2]));
      h[d[i]] = add(h[d[i]], add(h[d[i]], e[d[i]-2]));
    }
    if(d[i] < n-1){
      ans = add(ans, add(g[d[i]], h[d[i]+2]));
      g[d[i]] = add(g[d[i]], add(g[d[i]], h[d[i]+2]));
    }
  }
  ans = add(ans, add(f[zer], -1));
  ans = add(ans, add(f[one], -1));
  printf("%d\n", ans);
  
  for(int i=0; i<=n; i++)
    e[i] = h[i] = g[i] = 0;
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
/** 4
 * 0 2 1 0
 * 
 * {0}, {0}, {0, 0}, {1}, {0, 2}, {0, 1}, {0, 2, 0}
 * 
 **/
