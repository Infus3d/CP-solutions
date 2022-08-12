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

const int N = 405;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

ll dp[N][N][N];
map<ll, int> mk;
ll n, d, a[N], b[N], c[N], cnt;

/*
 * 1 1 3 3 3 5 3 3 1 1
 * */

ll rec(int l, int r, ll x){
  assert(l > 0 && l <= n && r > 0 && r <= n);
  if(l == r) return min(abs(c[x]-a[l]), min(d-c[x]+a[l], d-a[l]+c[x]));
  ll &ret = dp[l][r][x];
  if(~ret) return ret;
  
  ret = 0LL;
  ll leftside = rec(l, r-1, b[r]) + min(abs(c[x]-a[r]), min(d-c[x]+a[r], d-a[r]+c[x]));
  ll rightside = rec(l+1, r, b[l]) + min(abs(c[x]-a[l]), min(d-c[x]+a[l], d-a[l]+c[x]));
  ret = min(leftside, rightside);
  
  if(a[l] == a[r]){
    int leftbound = l, rightbound = r;
    while(leftbound < r && a[leftbound+1] == a[leftbound]) leftbound++;
    while(rightbound > l && a[rightbound-1] == a[rightbound]) rightbound--;
    
    //~ for(int i=l; i<=leftbound+1; i++)
      //~ for(int j=r; j>=max(i, rightbound-1); j--)
        //~ if(!(i == l && j == r))
          //~ ret = min(ret, rec(i, j, b[r]) + min(abs(c[x]-a[r]), d-a[r]+c[x]));
    //~ if(rightbound <= leftbound) ret = min(ret, min(abs(c[x]-a[r]), d-a[r]+c[x]));
    
    ll cur = 0LL;
    if(rightbound > leftbound)
      cur = rec(leftbound+1, rightbound-1, b[r]);
    ret = min(ret, cur + min(abs(c[x]-a[r]), min(d-c[x]+a[r], d-a[r]+c[x])));
  }
  return ret;
}

void solve(){
  scanf("%lld%lld", &n, &d);
    
  mk.clear(); cnt = 0;
  mk[0] = mk[d] = 1;
  for(int i=1; i<=n; i++){
    scanf("%lld", &a[i]);
    mk[a[i]] = 1;
  }
  for(auto &i : mk) 
    i.ss = cnt++;
  
  c[mk[0]] = 0, c[mk[d]] = d;
  for(int i=1; i<=n; i++) b[i] = mk[a[i]], c[b[i]] = a[i];
  
  for(int i=0; i<=n; i++)
    for(int j=0; j<=n; j++)
      for(int k=0; k<=cnt; k++)
        dp[i][j][k] = -1;
  printf("%lld\n", rec(1, n, mk[0]));
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int t=1; t<=testcase; t++){
    printf("Case #%d: ", t);
    solve();
  }
  return 0;
}
