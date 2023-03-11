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

int m;
long long T[N<<2];

struct Pointa{
  long long x, y, v, idx;
  Pointa() {}
  Pointa(long long _x, long long _y, long long _v, long long _idx) : x(_x), y(_y), v(_v), idx(_idx) {}
  bool operator<(const Pointa &p){
    return (y * p.x < x * p.y);
  }
};

struct Pointb{
  long long x, y, v, idx;
  Pointb() {}
  Pointb(long long _x, long long _y, long long _v, long long _idx) : x(_x), y(_y), v(_v), idx(_idx) {}
  bool operator<(const Pointb &p){
    return (y * (p.x - m) < (x - m) * p.y);
  }
};

void upd(int x, long long val, int l, int r, int v){
  if(l == r){
    T[v] += val;
    return;
  }
  if(x <= mid(l, r))
    upd(x, val, l, mid(l, r), v<<1);
  else
    upd(x, val, mid(l, r)+1, r, v<<1|1);
  
  T[v] = T[v<<1] + T[v<<1|1];
}

long long sum(int x, int y, int l, int r, int v){
  if(y < l || r < x) return 0LL;
  if(x <= l && r <= y) return T[v];
  return sum(x, y, l, mid(l, r), v<<1) + sum(x, y, mid(l, r)+1, r, v<<1|1);
}

void solve(){
  int n;
  scanf("%d%d", &n, &m);
  vector<long long> x(n), y(n), v(n);
  vector<Pointa> a(n);
  vector<Pointb> b(n);
  vector<int> idxA(n+1);
  for(int i=0; i<n; i++){
    scanf("%lld%lld%lld", &x[i], &y[i], &v[i]);
    a[i] = Pointa(x[i], y[i], v[i], i);
    b[i] = Pointb(x[i], y[i], v[i], i);
  }
  sort(a.begin(), a.end());
  for(int i=0; i<n; i++){
    idxA[a[i].idx] = i+1;
  }
  
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  vector<long long> ans(n);
  
  for(int i=0; i<n; i++){
    ans[b[i].idx] += sum(1, idxA[b[i].idx]-1, 1, n, 1);
    upd(idxA[b[i].idx], b[i].v, 1, n, 1);
  }
  
  for(int i=0; i<n; i++){
    printf("%lld\n", ans[i]);
  }
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
