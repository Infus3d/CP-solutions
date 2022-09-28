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

int d[N], T[N<<2];

void build_tree(int l, int r, int v){
  if(l == r){
    T[v] = d[l];
    return;
  }
  build_tree(l, mid(l, r), v<<1);
  build_tree(mid(l, r)+1, r, v<<1|1);
  T[v] = __gcd(T[v<<1], T[v<<1|1]);
}

int get(int x, int y, int l, int r, int v){
  if(r < x || y < l) return 0;
  if(x <= l && r <= y) return T[v];
  return __gcd(get(x, y, l, mid(l, r), v<<1), get(x, y, mid(l, r)+1, r, v<<1|1));
}

void solve(){
  int n; scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &d[i]);
  }
  build_tree(1, n, 1);
  
  int l = 1;
  vector<int> ans(n+1);
  for(int i=1; i<=n; i++){
    while(l <= i && get(l, i, 1, n, 1) < i-l+1) l++;
    if(get(l, i, 1, n, 1) == i-l+1){
      ans[i] = 1;
      l = i+1;
    }
    ans[i] += ans[i-1];
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
