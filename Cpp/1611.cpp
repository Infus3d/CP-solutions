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
const ll INF = 1e18;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int testcase;
int n, k, d[N], fr[N], ans;
vector<int> E[N];
bool win;

void dfs(int x, int par, int lvl){
  for(int i : E[x])
    if(i ^ par){
      if(d[i] > lvl+1)
        dfs(i, x, lvl+1);
      else
        ans++;
    }
  
  if(sz(E[x]) == 1 && x > 1)
    win = true;
}

void solve(){
  queue<int> Q;
  scanf("%d%d", &n, &k);
  for(int i=1; i<=k; i++){
    scanf("%d", &fr[i]);
    Q.push(fr[i]);
  }
  for(int i=1; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    E[a].pb(b);
    E[b].pb(a);
    d[i] = d[i+1] = MOD;
  }
  for(int i=1; i<=k; i++) d[fr[i]]=0;
  
  while(!Q.empty()){
    int tr = Q.front(); Q.pop();
    for(int i : E[tr])
      if(d[i] > d[tr]+1)
        d[i] = d[tr]+1, Q.push(i);
  }
  
  ans = 0;
  win = false;
  dfs(1, 0, 0);
  
  if(win)
    puts("YES");
  else
    puts("NO");
  
  for(int i=1; i<=n; i++) E[i].clear();
}

int main(){
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
