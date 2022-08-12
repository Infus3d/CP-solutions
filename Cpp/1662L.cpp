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

map<ll, int> mk;
int n, c, cnt;
int T[N*12];
ll t[N], a[N];

void build_tree(int l, int r, int v){
  if(l == r){
    T[v] = -1;
    return;
  }
  build_tree(l, mid(l, r), v<<1);
  build_tree(mid(l, r)+1, r, v<<1|1);
  T[v] = max(T[v<<1], T[v<<1|1]);
}

void upd(int x, int val, int l, int r, int v){
  if(l == r){
    umax(T[v], val);
    return;
  }
  if(x <= mid(l, r))
    upd(x, val, l, mid(l, r), v<<1);
  else
    upd(x, val, mid(l, r)+1, r, v<<1|1);
  T[v] = max(T[v<<1], T[v<<1|1]);
}

int get(int x, int y, int l, int r, int v){
  if(r < x || y < l) return -1;
  if(x <= l && r <= y)  return T[v];
  return max(get(x, y, l, mid(l, r), v<<1), get(x, y, mid(l, r)+1, r, v<<1|1));
}

void solve(){
  scanf("%d%d", &n, &c);
  for(int i=1; i<=n; i++) scanf("%lld", &t[i]);
  for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
  mk[0] = 1;
  for(int i=1; i<=n; i++){
    ll bound = 1LL * t[i] * c;
    mk[a[i]-bound] = 1;
    mk[a[i]+bound] = 1;
    mk[a[i]] = 1;
  }
  for(auto &i : mk) i.ss = ++cnt;
  
  int ans = 0;
  build_tree(1, cnt, 1);
  upd(mk[0], 0, 1, cnt, 1);
  for(int i=1; i<=n; i++){
    ll bound = 1LL * t[i] * c;
    int tr = get(mk[a[i]-bound], mk[a[i]+bound], 1, cnt, 1);
    printf("a[i]-bound:%lld, mk[a[i]-bound]:%d\n", a[i]-bound, mk[a[i]-bound]);
    printf("a[i]+bound:%lld, mk[a[i]+bound]:%d\n", a[i]+bound, mk[a[i]+bound]);
    printf("tr --> %d\n", tr);
    if(tr == -1) continue;
    upd(mk[a[i]], tr+1, 1, cnt, 1);
    umax(ans, tr+1);
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
