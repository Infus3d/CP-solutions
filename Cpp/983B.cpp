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

const int N = 5e3+2;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, q, a[N], dp[N][N];
int l, r;

void solve(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);
  for(int i=1; i<=n; i++) dp[0][i] = a[i];
  for(int i=1; i<n; i++)
    for(int j=1; j<=n-i; j++)
      dp[i][j] = dp[i-1][j] ^ dp[i-1][j+1];
  
  for(int i=1; i<n; i++)
    for(int j=1; j<=n-i; j++)
      umax(dp[i][j], max(dp[i-1][j], dp[i-1][j+1]));
  
  scanf("%d", &q);
  while(q--){
    scanf("%d%d", &l, &r);
    printf("%d\n", dp[r-l][l]);
  }
}

int main(){
  int testcase = 1;
  while(testcase--){
    solve();
  }
  
  return 0;
}
