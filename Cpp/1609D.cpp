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

int testcase;
int n, k, d[N], w[N], a, b, p;

int par(int x){
  if(d[x] == x)
    return x;
  return d[x] = par(d[x]);
}

void solve(){
  scanf("%d%d", &n, &k);
  for(int i=1; i<=n; i++) d[i] = i, w[i] = 1;
  for(int i=1; i<=k; i++){
    scanf("%d%d", &a, &b);
    if(par(a) != par(b))
      w[par(b)] += w[par(a)], d[par(a)] = d[par(b)];
    else
      p++;
    
    int ans = 0;
    vector<int> vis(n+1, 0), v;
    for(int j=1; j<=n; j++)
      if(!vis[par(j)]){
        vis[par(j)] = 1;
        v.pb(w[par(j)]);
      }
    
    sort(all(v)); reverse(all(v));
    for(int j=0; j<min(sz(v), p+1); j++)
      ans += v[j];
    printf("%d\n", ans-1);
  }
}

int main(){
  testcase = 1;
  while(testcase--){
    solve();
  }
  return 0;
}
