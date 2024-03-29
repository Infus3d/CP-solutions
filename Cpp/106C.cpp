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
 
const int N = 1e3+2;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, c0, d0;
int a[N], b[N], c[N], d[N];
int dp[N];

int main(){
  scanf("%d%d%d%d", &n, &m, &c0, &d0);
  for(int i=1; i<=m; i++)
    scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
  
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for(int i=1; i<=m; i++){
    for(int j=n; j>=0; j--)
      if(~dp[j]){
        for(int k=0; k*b[i] <= a[i]; k++)
          if(j+(k*c[i]) <= n)
            dp[j+(k*c[i])] = max(dp[j+(k*c[i])], dp[j] + d[i]*k);
      }
  }
  
  int ans = 0;
  for(int i=0; i<=n; i++)
    if(~dp[i])
      ans = max(ans, dp[i] + (n-i)/c0 * d0);
  printf("%d\n", ans);
  
	return 0;
}
