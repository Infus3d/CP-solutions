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
#define y1 your_name_engraved_herein

using namespace std;
// using namespace __gnu_pbds;

const int N = 2e5+2;
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

int n, c[30];
ll d[N], dp[N][5];
char s[N];

int main(){
  scanf("%d", &n);
  scanf("%s", s+1);
  for(int i=1; i<=n; i++)
    scanf("%lld", &d[i]);
  
  c['h'-'a'] = 1;
  c['a'-'a'] = 2;
  c['r'-'a'] = 3;
  c['d'-'a'] = 4;
  
  for(int i=0; i<=n; i++)
    for(int j=0; j<5; j++)
      dp[i][j] = INF;
  
  dp[0][0] = 0;
  for(int i=1; i<=n; i++){
    for(int j=0; j<5; j++){
      if(c[s[i]-'a'] == j && j > 0){
        dp[i][j-1] = dp[i-1][j-1] + d[i];
        umin(dp[i][j], min(dp[i-1][j-1], dp[i-1][j]));
      }
      else
        umin(dp[i][j], dp[i-1][j]);
    }
  }
  
  ll ans = INF;
  for(int i=0; i<4; i++)
    ans = min(ans, dp[n][i]);
  printf("%lld\n", ans);
  
  
  return 0;
}
