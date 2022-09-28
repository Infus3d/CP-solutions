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

long long D, X;
long long Q[N], L[N], V[N];
int n;

set<pair<long long, long long>> setik;
map<long long, long long> vis;

long long getAvailable(long long x){
  if(setik.empty()) return x;
  auto it = setik.upper_bound({x, D});
  if(it == setik.begin()){
    return (it->first)-1;
  }
  it--;
  if(it->ss < x) return x;
  return (it->ff)-1;
}

long long getNextEnd(long long x){
  assert(x > 0ll);
  if(setik.empty()) return 1;
  auto it = setik.upper_bound({x, D});
  if(it == setik.begin()) return 1;
  return (--it)->ss+1;
}

void unite(long long x, long long y){
  //~ printf("Entering as x -> %lld, y -> %lld\n", x, y);
  assert(0 < x && 0 < y && x <= D && y <= D);
  if(setik.empty()){
    setik.insert({x, y});
    return;
  }
  auto itx = setik.upper_bound({x, D});
  auto ity = setik.upper_bound({y, D});
  if(itx != setik.begin() && ity != setik.end()){
    //~ puts("Inside first");
    if(itx->ss == x-1 && y+1 == ity->ff){
      long long xx = itx->ff, yy = ity->ss;
      setik.erase(itx); setik.erase(ity);
      setik.insert({xx, yy});
    }
    else if(itx->ss == x-1 && y+1 != ity->ff){
      long long xx = itx->ff, yy = y;
      setik.erase(itx);
      setik.insert({xx, yy});
    }
    else if(itx->ss != x-1 && y+1 == ity->ff){
      long long xx = x, yy = ity->ss;
      setik.erase(ity);
      setik.insert({xx, yy});
    }
    else{
      setik.insert({x, y});
    }
  }
  else if(itx != setik.begin()){
    //~ puts("Inside second");
    itx--;
    if(itx->ss == x-1){
      long long xx = itx->ff, yy = y;
      setik.erase(itx);
      setik.insert({xx, yy});
    }
    else{
      setik.insert({x, y});
    }
  }
  else if(ity != setik.end()){
    //~ puts("Inside third");
    if(y+1 == ity->ff){
      long long xx = x, yy = ity->ss;
      setik.erase(ity);
      setik.insert({xx, yy});
    }
    else{
      setik.insert({x, y});
    }
  }
  else{
    assert(false);
    printf("This should be impossible: x->%lld, y->%lld\n", x, y);
  }
}

void solve(){
  setik.clear();
  vis.clear();
  scanf("%lld%d%lld", &D, &n, &X);
  vector<int> ord;
  for(int i=0; i<n; i++){
    scanf("%lld%lld%lld", &Q[i], &L[i], &V[i]);
    ord.push_back(i);
  }
  sort(all(ord), [&](int x, int y){
    if(V[x] != V[y])
      return V[x] > V[y];
    else
      return D-L[x] > D-L[y];
  });
  long long ans = 0;
  for(int idx : ord){
    assert(sz(setik) < (int)1e6);
    //~ printf("idx -> %d, Q[idx]->%lld, L[idx]->%lld, V[idx]->%lld, ans->%lld\n", idx, Q[idx], L[idx], V[idx], ans);
    long long cur = D - L[idx];
    while(Q[idx] > 0 && cur > 0){
      //~ printf("Q[idx] -> %lld, cur -> %lld\n", Q[idx], cur);
      long long aidx = getAvailable(cur);
      if(aidx < 1) break;
      long long nidx = getNextEnd(aidx);
      assert(nidx > 0ll);
      //~ printf("Dumping set:\n");
      //~ for(auto j : setik){
        //~ printf("***** %lld %lld\n", j.ff, j.ss);
      //~ }
      //~ printf("aidx -> %lld, nidx -> %lld\n", aidx, nidx);
      long long cando = X - vis[aidx];
      if(cando > Q[idx]){
        ans += Q[idx] * V[idx];
        vis[aidx] += Q[idx];
        Q[idx] = 0;
      }
      else if(cando == Q[idx]){
        ans += Q[idx] * V[idx];
        vis[aidx] += Q[idx];
        Q[idx] = 0;
        unite(aidx, aidx);
        cur = aidx-1;
      }
      else{
        long long total = cando + (aidx - nidx) * X;
        if(total > Q[idx]){
          ans += Q[idx] * V[idx];
          Q[idx] -= cando;
          long long xx = Q[idx] / X;
          vis[aidx-xx-1] += Q[idx] % X;
          unite(aidx-xx, aidx);
          Q[idx] = 0;
          cur = aidx-xx-1;
        }
        else{
          ans += total * V[idx];
          Q[idx] -= total;
          unite(nidx, aidx);
          cur = nidx-1;
        }
      }
    }
  }
  printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int i=1; i<=testcase; i++){
    //~ cout << "Case #" << i << ": ";
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}
