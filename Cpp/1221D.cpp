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
 
const int N = 3e5+2;
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

int testcase;
ll n, dp[N][3], a[N], b[N];

void solve(){
  scanf("%lld", &n);
  for(int i=1; i<=n; i++)
    scanf("%lld%lld", a+i, b+i);
  for(int i=0; i<=n; i++)
    for(int j=0; j<3; j++)
      dp[i][j] = INF;
  
  dp[0][0] = 0LL;
  for(int i=1; i<=n; i++)
    for(int j=0; j<3; j++){
      for(int v=0; v<3; v++){
        if(i == 1 || a[i-1]+v != a[i]+j)
          dp[i][j] = min(dp[i][j], dp[i-1][v] + b[i]*j);
      }
    }
  
  ll ans = INF;
  for(int i=0; i<3; i++)
    ans = min(ans, dp[n][i]);
  printf("%lld\n", ans);
}

int main(){
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  
  return 0;
}
