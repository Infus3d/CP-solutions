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

const int N = 2e5+55;
const int K = 2e5+50;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, q, d[N];

struct node{
  int minval, maxval, lz;
} T[N<<2];

void push(int v){
  if(T[v].lz == -1) return;
  
  T[v<<1].minval = T[v<<1].maxval = T[v<<1].lz = T[v].lz;
  T[v<<1|1].minval = T[v<<1|1].maxval = T[v<<1|1].lz = T[v].lz;
  
  T[v].lz = -1;
}

int findzero(int x, int l, int r, int v){
  if(r < x) return -1;
  if(x <= l && T[v].minval == 1) return -1;
  
  if(l == r){
    T[v].minval = T[v].maxval = T[v].lz = 1;
    return l;
  }
  
  push(v);
  int lef = findzero(x, l, mid(l, r), v<<1);
  if(lef != -1){
    T[v].minval = min(T[v<<1].minval, T[v<<1|1].minval);
    T[v].maxval = max(T[v<<1].maxval, T[v<<1|1].maxval);
    return lef;
  }
  int rig = findzero(x, mid(l, r)+1, r, v<<1|1);
  T[v].minval = min(T[v<<1].minval, T[v<<1|1].minval);
  T[v].maxval = max(T[v<<1].maxval, T[v<<1|1].maxval);
  return rig;
}

int findone(int x, int l, int r, int v){
  if(r < x) return -1;
  if(x <= l && T[v].maxval == 0) return -1;
  
  if(l == r){
    T[v].minval = T[v].maxval = T[v].lz = 0;
    return l;
  }
  
  push(v);
  int lef = findone(x, l, mid(l, r), v<<1);
  if(lef != -1){
    T[v].minval = min(T[v<<1].minval, T[v<<1|1].minval);
    T[v].maxval = max(T[v<<1].maxval, T[v<<1|1].maxval);
    return lef;
  }
  int rig = findone(x, mid(l, r)+1, r, v<<1|1);
  T[v].minval = min(T[v<<1].minval, T[v<<1|1].minval);
  T[v].maxval = max(T[v<<1].maxval, T[v<<1|1].maxval);
  return rig;
}

void setUpd(int x, int y, int val, int l, int r, int v){
  if(r < x || y < l)
    return;
  if(x <= l && r <= y){
    T[v].minval = T[v].maxval = T[v].lz = val;
    return;
  }
  push(v);
  setUpd(x, y, val, l, mid(l, r), v<<1);
  setUpd(x, y, val, mid(l, r)+1, r, v<<1|1);
  
  T[v].minval = min(T[v<<1].minval, T[v<<1|1].minval);
  T[v].maxval = max(T[v<<1].maxval, T[v<<1|1].maxval);
}

int findMaxOne(int l, int r, int v){
  if(l == r)
    return l;
  
  push(v);
  if(T[v<<1|1].maxval == 1)
    return findMaxOne(mid(l, r)+1, r, v<<1|1);
  else
    return findMaxOne(l, mid(l, r), v<<1);
}

void solve(){
  scanf("%d%d", &n, &q);
  for(int i=1; i<=K*4; i++)
    T[i].lz = -1;
  for(int i=1; i<=n; i++){
    scanf("%d", &d[i]);
    int idx = findzero(d[i], 1, K, 1);
    if(d[i] < idx)
      setUpd(d[i], idx-1, 0, 1, K, 1);
  }
  
  while(q--){
    int k, x;
    scanf("%d%d", &k, &x);
    int idx = findone(d[k], 1, K, 1);
    if(d[k] < idx)
      setUpd(d[k], idx-1, 1, 1, K, 1);
    
    d[k] = x;
    idx = findzero(d[k], 1, K, 1);
    if(d[k] < idx)
      setUpd(d[k], idx-1, 0, 1, K, 1);
    
    printf("%d\n", findMaxOne(1, K, 1));
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
