#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"
 
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define db puts("*****")
#define mid(x , y) ((x+y)>>1)
#define ff first
#define ss second
#define all(x)	x.begin(),x.end()
#define ll long long
#define sqr(x)	((x)*(x))
#define pii pair <int , int>
#define pll pair <ll, ll>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day
 
using namespace std;
// using namespace __gnu_pbds;
 
const int N = 18;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;
const ll INF = 1e18+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, k, a, b, c;
ll dp[(1<<N)+2][N+2];
ll cost[N][N], d[N], ans;

int main(){
  scanf("%d%d%d", &n, &m, &k);
  for(int i=0; i<n; i++) scanf("%lld", &d[i]);
  for(int i=1; i<=k; i++){
    scanf("%d%d%d", &a, &b, &c);
    a--, b--;
    cost[a][b] = c;
  }
  
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for(int mask=1; mask<(1<<n); mask++){
    for(int i=0; i<n; i++){
      if(!(mask&(1<<i))) continue;
      int newMask = mask^(1<<i);
      for(int j=0; j<n; j++){
        if(~dp[newMask][j]){
          if(dp[mask][i] == -1)
            dp[mask][i] = dp[newMask][j] + d[i] + (!newMask ? 0 : cost[j][i]);
          else
            umax(dp[mask][i], dp[newMask][j] + d[i] + (!newMask ? 0 : cost[j][i]));
        }
      }
    }
  }
  
  for(int mask=0; mask<(1<<n); mask++)
    if(__builtin_popcount(mask) == m){
      for(int i=0; i<n; i++)
        if(~dp[mask][i])
          ans = max(ans, dp[mask][i]);
    }
  
  printf("%lld\n", ans);
  return 0;
}
