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
 
const int N = 5e2+2;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, b, mod;
int d[N], dp[2][N][N];

int add(int x, int y){
  return (0LL + x + y) % mod;
}

int main(){
  scanf("%d%d%d%d", &n, &m, &b, &mod);
  for(int i=1; i<=n; i++) scanf("%d", d+i);
  
  dp[0][0][0] = 1;
  for(int i=1; i<=n; i++){
    for(int line=0; line<=m; line++){
      for(int bug=0; bug<=b; bug++){
        dp[1][line][bug] = dp[0][line][bug];
        if(line < m && bug+d[i] <= b)
          dp[0][line+1][bug+d[i]] = add(dp[0][line+1][bug+d[i]], dp[0][line][bug]);
      }
    }
    
    for(int line=0; line<=m; line++)
      for(int bug=0; bug<=b; bug++){
        dp[0][line][bug] = dp[1][line][bug];
        dp[1][line][bug] = 0;
      }
  }
  
  int ans = 0;
  for(int bug=0; bug<=b; bug++)
    ans = add(ans, dp[0][m][bug]);
  printf("%d\n", ans);
  
  return 0;
}
