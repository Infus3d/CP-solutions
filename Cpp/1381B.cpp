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
 
const int N = 2e3+2;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int dp[2*N][N][2], d[2*N], mx[2*N];
int testcase, n;

int rec(int ind, int x, int v){
  if(x > n || ind-x-1 > n) return 0;
  if(ind > 2*n){
    if(x == n)  return 1;
    else return 0;
  }
  
  int &ret = dp[ind][x][v];
  if(~ret) return ret;
  
  ret = 0;
  if(d[ind] > mx[ind-1])
    ret |= rec(ind+1, x+(!v), v^1);
  ret |= rec(ind+1, x+v, v);
  return ret;
}

void solve(){
  scanf("%d", &n);
  for(int i=1; i<=2*n; i++){
    scanf("%d", &d[i]);
    mx[i] = max(mx[i-1], d[i]);
  }
  
  for(int i=0; i<=2*n+1; i++)
    for(int j=0; j<=n+1; j++)
      for(int v=0; v<2; v++)
        dp[i][j][v] = -1;
  
  if(rec(2, 1, 1))
    puts("YES");
  else
    puts("NO");
}

int main(){
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  
  return 0;
}
