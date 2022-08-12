#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
#define all(x)	x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 1e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, root, cnt;
vector<int> E[N], curLeaf, prevLeaf, leaf;

void dfs(int x, int par){
  for(int i : E[x])
    if(i != par)
      dfs(i, x);
  if(sz(E[x]) == 1)
    leaf.pb(x);
}

void solve(){
  scanf("%d%d", &n, &root);
  for(int i=1; i<n; i++){
    int a, b; scanf("%d%d", &a, &b);
    E[a].pb(b);
    E[b].pb(a);
  }
  
  vector<vector<int>> branch (sz(E[root]), vector<int>());
  vector<pii> ans;
  vector<pii> v(sz(E[root]));
  cnt = 0;
  for(int i : E[root]){
    dfs(i, root);
    branch[cnt] = leaf;
    leaf.clear();
    cnt++;
  }
  
  for(int i=0; i<sz(E[root]); i++) v[i] = {sz(branch[i]), i};
  sort(all(v)); reverse(all(v));
  //~ sort(all(v), [&branch](int& x, int& y){
    //~ if(x >= sz(E[root]) || y >= sz(E[root])) {
        //~ puts("JUST FOR WA"); 
        //~ exit(0);
    //~ }
    //~ return sz(branch[x]) > sz(branch[y]);
  //~ });
  
  assert(sz(v) > 0);
  prevLeaf = branch[v[0].ss];
  for(int i=1; i<sz(E[root]); i++){
    //~ if(i >= sz(v) || v[i] >= sz(E[root])) {puts("JUST FOR WA"); return; }
    curLeaf = branch[v[i].ss];
    while(sz(curLeaf) > 0 && sz(prevLeaf) > 0){
      int a = curLeaf.back();
      int b = prevLeaf.back();
      ans.pb({a, b});
      //~ if(sz(prevLeaf) < 1 || sz(curLeaf) < 1) {puts("JUST FOR WA"); return;}
      prevLeaf.pop_back();
      curLeaf.pop_back();
    }
    if(sz(prevLeaf) == 0)
      prevLeaf = curLeaf;
    curLeaf.clear();
  }
  while(sz(prevLeaf) > 0){
    int a = prevLeaf.back();
    ans.pb({root, a});
    //~ if(sz(prevLeaf) < 1) {puts("JUST FOR WA"); return;}
    prevLeaf.pop_back();
  }
  
  printf("%d\n", sz(ans));
  for(pii i : ans)
    printf("%d %d\n", i.ff, i.ss);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
