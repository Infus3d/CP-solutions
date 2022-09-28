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

const int N = 1e6+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

typedef unsigned long long ull;
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

ull random_values[N];
ull T[N<<2];
map<ull, bool> lookup;

int n;

void upd(int x, ull val, int l, int r, int v){
  if(l == r){
    T[v] = val;
    return;
  }
  if(x <= mid(l, r))
    upd(x, val, l, mid(l, r), v<<1);
  else
    upd(x, val, mid(l, r)+1, r, v<<1|1);
  T[v] = T[v<<1] + T[v<<1|1];
}

ull get(int x, int y, int l, int r, int v){
  if(r < x || y < l) return 0;
  if(x <= l && r <= y) return T[v];
  return get(x, y, l, mid(l, r), v<<1) + get(x, y, mid(l, r)+1, r, v<<1|1);
}

bool beats_by_one(int l1, int r1, int l2, int r2){
  ull hash1 = get(l1, r1, 1, n, 1);
  ull hash2 = get(l2, r2, 1, n, 1);
  return lookup[hash1 - hash2];
}

void solve(){
  scanf("%d", &n);
  vector<int> a(n+1);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    upd(i, random_values[a[i]], 1, n, 1);
  }
  int q; scanf("%d", &q);
  int ans = 0;
  while(q--){
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if(t == 1){
      upd(x, random_values[y], 1, n, 1);
    } else {
      if((y-x+1) % 2 == 0) continue;
      if(beats_by_one(x, mid(x, y), mid(x, y)+1, y)){
        ans++;
        continue;
      }
      ans += beats_by_one(mid(x, y), y, x, mid(x, y)-1);
    }
  }
  printf("%d\n", ans);
}


int main(){
  //~ printf("%d\n", lookup[0]);
  for(int i=1; i<=(int)1e6; i++){
    random_values[i] = rng();
    lookup[random_values[i]] = true;
    //~ if(i < 20){
      //~ printf("%llu\n", random_values[i]);
    //~ }
  }
  int testcase = 1;
  scanf("%d", &testcase);
  for(int i=1; i<=testcase; i++){
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}

