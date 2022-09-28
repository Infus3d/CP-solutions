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

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

void solve(){
  int n, m, comp = (1<<30)-1;
  scanf("%d%d", &n, &m);
  vector<int> allowed(n+1, comp);
  vector<vector<pii>> E(n+1);
  for(int i=0; i<m; i++){
    int x, y, v;
    scanf("%d%d%d", &x, &y, &v);
    allowed[x] &= v;
    allowed[y] &= v;
    E[x].push_back({y, v});
    E[y].push_back({x, v});
  }
  vector<int> ans(n+1, 0);
  for(int i=1; i<=n; i++){
    int required = 0;
    for(pii j : E[i]){
      required |= (j.ss & (allowed[j.ff] ^ comp));
      if(j.ff == i) required |= j.ss;
    }
    ans[i] |= required;
    for(pii j : E[i]){
      ans[j.ff] |= (ans[i] ^ j.ss);
    }
  }
  for(int i=1; i<=n; i++){
    printf("%d ", ans[i]);
  }
  puts("");
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
/*
0 1 1 1 1

*/
