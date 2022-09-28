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

const int N = 3e5+2;
const int K = 1e6+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int P[K], d[N], n, m;
pair<long long, int> T[N<<2];

void build(int l, int r, int v){
  if(l == r){
    T[v] = {d[l], d[l]};
    return;
  }
  build(l, mid(l, r), v<<1);
  build(mid(l, r)+1, r, v<<1|1);
  T[v] = {T[v<<1].ff + T[v<<1|1].ff, max(T[v<<1].ss, T[v<<1|1].ss)};
}

void upd(int x, int y, int l, int r, int v){
  if(T[v].ss <= 2) return;
  if(r < x || y < l) return;
  if(l == r){
    d[l] = P[d[l]];
    T[v] = {d[l], d[l]};
    return;
  }
  upd(x, y, l, mid(l, r), v<<1);
  upd(x, y, mid(l, r)+1, r, v<<1|1);
  T[v] = {T[v<<1].ff + T[v<<1|1].ff, max(T[v<<1].ss, T[v<<1|1].ss)};
}

long long get(int x, int y, int l, int r, int v){
  if(r < x || y < l) return 0;
  if(x <= l && r <= y) return T[v].ff;
  return get(x, y, l, mid(l, r), v<<1) + get(x, y, mid(l, r)+1, r, v<<1|1);
}

void solve(){
  for(int i=1; i<=(int)1e6; i++){
    for(int j=i; j<=(int)1e6; j+=i)
      P[j]++;
  }
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++){
    scanf("%d", &d[i]);
  }
  build(1, n, 1);
  while(m--){
    int t, a, b;
    scanf("%d%d%d", &t, &a, &b);
    if(t == 1){
      upd(a, b, 1, n, 1);
    } else {
      printf("%lld\n", get(a, b, 1, n, 1));
    }
  }
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
