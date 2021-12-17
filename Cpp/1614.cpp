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
const int MOD = 1e9+7;
const int K = 1e3+2;
const int MAX = (1LL<<30)-1;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int testcase;
int n, d[N], f[N], m, e[31][2], pw[N], fac[N];
int a, b, c, O;
vector<pii> E[N];

int add(int x, int y){
  return (0LL + x + y) % MOD;
}

int mul(int x, int y){
  return (1LL * x * y) % MOD;
}

int bmod(int x, int y){
  if(y == 0) return 1;
  if(y == 1) return x;
  ll tr = bmod(x, y/2);
  tr = mul(tr, tr);
  if(y&1) tr = mul(tr, x);
  return tr;
}

int choose(int nn){
  int cur = 0;
  for(int i=1; i<=nn; i+=2)
    cur = add(cur, mul(fac[nn], bmod(mul(fac[i], fac[nn-i]), MOD-2)));
  return cur;
}

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++) f[i] = MAX;
  for(int i=1; i<=m; i++){
    scanf("%d%d%d", &a, &b, &c);
    E[a].pb({b, c});
    O |= c;
  }
  
  int cur = 0;
  for(int i=1; i<=n; i++){
    sort(all(E[i])); reverse(all(E[i]));
    cur &= f[i];
    for(pii u : E[i]){
      f[u.ff+1] &= cur;
      cur |= (MAX ^ u.ss);
    }
    
    d[i] = cur^MAX;
  }
  
  //~ db;
  //~ for(int i=1; i<=n; i++)
    //~ printf("%d ", d[i]);
  //~ puts("");
  
  int ans = 0;
  pw[0] = 1, fac[0] = 1;
  for(int i=1; i<=n; i++){
    fac[i] = mul(fac[i-1], i);
    pw[i] = mul(pw[i-1], 2);
    for(int j=0; j<31; j++)
      e[j][(d[i]>>j)&1]++;
  }
  
  for(int i=0; i<31; i++)
    ans = add(ans, mul((1<<i)&O, pw[n-1]));
  printf("%d\n", ans);
  
  for(int i=1; i<=n; i++) E[i].clear();
  memset(e, 0, sizeof(e));
  O = 0;
}

int main(){
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
