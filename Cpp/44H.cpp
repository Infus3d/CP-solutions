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
 
const int N = 52;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

ll n, dp[N][10], v[N][10];
char s[N];

int main(){
  scanf("%s", s); n = strlen(s);
  for(ll i=0; i<10; i++) dp[0][i] = 1, v[0][i] = (i == s[0]-'0' ? 1 : 0);
  for(ll i=1; i<n; i++){
    for(ll j=0; j<10; j++){
      ll num = j*2-(s[i]-'0');
        for(ll k=max(0LL, num-1); k<min(10LL, num+2); k++){
          dp[i][j] += dp[i-1][k];
          if(j == s[i]-'0')
            v[i][j] |= v[i-1][k];
        }
    }
  }
  
  ll ans = 0;
  for(ll i=0; i<10; i++)
    ans += dp[n-1][i] - v[n-1][i];
  printf("%lld\n", ans);
  
  
  return 0;
}
