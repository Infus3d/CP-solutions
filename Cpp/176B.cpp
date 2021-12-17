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
 
const int N = 1e5+2;
const int M = 600;
const int MOD = 1e9+7;
const int K = 1e3+2;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, dp[2][K], k, f;
char s[K], t[K];
vector<int> cuts;

int main(){
  scanf("%s%s%d", s, t, &k); n = strlen(s);
  for(int i=0; i<n; i++){
    bool flag = true;
    int p = 0;
    for(int j=i; j<n; j++)
      if(s[j] != t[p++])
        flag = false;
    for(int j=0; j<i; j++)
      if(s[j] != t[p++])
        flag = false;
    if(flag) cuts.pb(i);
  }
  
  dp[0][0] = f = 1;
  for(int i=1; i<=k; i++){
    for(int j=0; j<n; j++)
      dp[1][j] = (0LL + dp[1][j] + f - dp[0][j] + MOD) % MOD;
    f = 0;
    for(int j=0; j<n; j++){
      dp[0][j] = dp[1][j];
      dp[1][j] = 0;
      f = (f + dp[0][j]) % MOD;
    }
  }
  
  int ans = 0;
  for(int i : cuts)
    ans = (ans + dp[0][i]) % MOD;
  printf("%d\n", ans);
  
  return 0;
}
