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
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, q, b, cnt[N], a[N], L[N], K[N], ans[N], T[N<<2];
set<int> nodes[N];
vector<int> E[N], Query[N];

void form_tree(int l, int r, int v){
  if(l == r){
    T[v] = 0;
    return;
  }
  form_tree(l, mid(l, r), v<<1);
  form_tree(mid(l, r)+1, r, v<<1|1);
}

void upd(int x, int val, int l, int r, int v){
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

int getSum(int x, int y, int l, int r, int v){
  if(r < x || y < l)
    return 0;
  if(x <= l && r <= y)
    return T[v];
  return getSum(x, y, l, mid(l, r), v<<1) + getSum(x, y, mid(l, r)+1, r, v<<1|1);
}

int getInd(int val, int l, int r, int v){
  if(val > T[v]) return -1;
  if(l == r)  return l;
  if(val > T[v<<1])
    return getInd(val-T[v<<1], mid(l, r)+1, r, v<<1|1);
  else
    return getInd(val, l, mid(l, r), v<<1);
}

void dfs(int x){
  if(cnt[a[x]] > 0){
    upd(cnt[a[x]], -1, 1, n, 1);
    nodes[cnt[a[x]]].erase(a[x]);
  }
  cnt[a[x]]++;
  upd(cnt[a[x]], +1, 1, n, 1);
  nodes[cnt[a[x]]].insert(a[x]);
  
  for(int i : Query[x]){
    int k = K[i];
    if(L[i] > 1)  
      k += getSum(1, L[i]-1, 1, n, 1);
    
    int ind = getInd(k, 1, n, 1);
    //~ printf("i:%d, ind:%d, K[i]:%d, k:%d, T[1]:%d\n", i, ind, K[i], k, T[1]);
    assert(ind == -1 || sz(nodes[ind]) > 0);
    ans[i] = (~ind ? *nodes[ind].begin() : ind);
  }
  
  for(int i : E[x]) dfs(i);
  
  upd(cnt[a[x]], -1, 1, n, 1);
  nodes[cnt[a[x]]].erase(a[x]);
  cnt[a[x]]--;
  if(cnt[a[x]] > 0){
    upd(cnt[a[x]], +1, 1, n, 1);
    nodes[cnt[a[x]]].insert(a[x]);
  }
}

void solve(){
  scanf("%d%d", &n, &q);
  for(int i=1; i<=n; i++){ 
    scanf("%d", &a[i]);
    E[i].clear();
    Query[i].clear();
    cnt[a[i]] = 0;
  }
  for(int i=2; i<=n; i++){
    scanf("%d", &b);
    E[b].pb(i);
  }
  
  form_tree(1, n, 1);
  for(int i=1; i<=q; i++){
    scanf("%d%d%d", &b, &L[i], &K[i]);
    Query[b].pb(i);
  }
  
  dfs(1);
  for(int i=1; i<=q; i++)
    printf("%d ", ans[i]);
  puts("");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
