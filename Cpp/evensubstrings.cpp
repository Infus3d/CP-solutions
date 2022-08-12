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

char s[N];

int n, q, res[64];
int T[N<<2][64], lz[N<<2];

void mergeit(int v){
  for(int i=0; i<64; i++)
    T[v][i] = T[v<<1][i] + T[v<<1|1][i];
}

void build(int l, int r, int v){
  if(l == r){
    T[v][0] = 1;
    return;
  }
  build(l, mid(l, r), v<<1);
  build(mid(l, r)+1, r, v<<1|1);
  mergeit(v);
}

void apply(int v, int val){
  vector<int> temp(64, 0);
  for(int i=0; i<64; i++)
    temp[i^val] += T[v][i];
  for(int i=0; i<64; i++)
    T[v][i] = temp[i];
  lz[v] ^= val;
}

void push(int v){
  if(!lz[v]) return;
  apply(v<<1, lz[v]);
  apply(v<<1|1, lz[v]);
  lz[v] = 0;
}

void upd(int x, int y, int val, int l, int r, int v){
  if(r < x || y < l) return;
  if(x <= l && r <= y){
    apply(v, val);
    return;
  }
  push(v);
  upd(x, y, val, l, mid(l, r), v<<1);
  upd(x, y, val, mid(l, r)+1, r, v<<1|1);
  mergeit(v);
}

void get(int x, int y, int l, int r, int v){
  if(r < x || y < l) return;
  if(x <= l && r <= y){
    for(int i=0; i<64; i++)
      res[i] += T[v][i];
    return;
  }
  push(v);
  get(x, y, l, mid(l, r), v<<1);
  get(x, y, mid(l, r)+1, r, v<<1|1);
  mergeit(v);
}

void solve(){
  scanf("%s", s); n = strlen(s);
  build(0, n, 1);
  for(int i=1; i<=n; i++) 
    upd(i, n, 1<<(s[i-1]-'a'), 0, n, 1);
  
  scanf("%d", &q);
  while(q--){
    int t, a, b; 
    char c;
    scanf("%d%d", &t, &a);
    if(t == 1){
      scanf("%d", &b);
      memset(res, 0, sizeof(res));
      get(a-1, b, 0, n, 1);
      
      ll ans = 0LL;
      for(int i=0; i<64; i++)
        ans += 1LL * res[i] * (res[i]-1) / 2LL;
      printf("%lld\n", ans);
    }
    else{
      scanf(" %c", &c);
      upd(a, n, (1<<(s[a-1]-'a')) ^ (1<<(c-'a')), 0, n, 1);
      s[a-1] = c;
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
