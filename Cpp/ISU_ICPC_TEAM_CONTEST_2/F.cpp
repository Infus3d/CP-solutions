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
const int K = 1e6;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m;
int P[N], pref[N], T[N<<2], lz[N<<2];

void build(int l, int r, int v){
  T[v] = lz[v] = 0;
  if(l == r){
    T[v] = pref[l];
    return;
  }
  build(l, mid(l, r), v<<1);
  build(mid(l, r)+1, r, v<<1|1);
  T[v] = min(T[v<<1], T[v<<1|1]);
}

void push(int v){
  if(lz[v] == 0) return;
  T[v<<1] += lz[v];
  T[v<<1|1] += lz[v];
  lz[v<<1] += lz[v];
  lz[v<<1|1] += lz[v];
  lz[v] = 0;
}

void upd(int x, int y, int l, int r, int v){
  if(r < x || y < l)  return;
  if(x <= l && r <= y){
    T[v]++;
    lz[v]++;
    return;
  }
  push(v);
  
  upd(x, y, l, mid(l, r), v<<1);
  upd(x, y, mid(l, r)+1, r, v<<1|1);
  T[v] = min(T[v<<1], T[v<<1|1]);
}

int get(int x, int y, int l, int r, int v){
  if(r < x || y < l) return INT_MAX;
  if(x <= l && r <= y) return T[v];
  push(v);
  return min(get(x, y, l, mid(l, r), v<<1), get(x, y, mid(l, r)+1, r, v<<1|1));
}

void solve(){
  build(0, K, 1);
  int ans = -INT_MAX;
  for(int i=n; i<=m; i++){
    upd(n-1, i-1, 0, K, 1);
    umax(ans, pref[i] - get(n-1, i-1, 0, K, 1));
  }
  printf("%d\n", ans);
}

int main(){
  for(int i=2; i<=K; i++){
    if(P[i] == 0){
      pref[i] = -1;
      for(int j=i+i; j<=K; j+=i)
        P[j] = i;
    }
    else{
      int k = i;
      while(P[k] > 0)
        k /= P[k], pref[i]++;
      pref[i]++;
    }
    pref[i] += pref[i-1];
  }
  
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(true){
    scanf("%d%d", &n, &m);
    if(n == -1 && m == -1) break;
    printf("%d. ", testcase++);
    solve();
  }
  return 0;
}
