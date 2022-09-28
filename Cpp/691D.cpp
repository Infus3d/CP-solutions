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

int find(int x, vector<int> &par){
  if(par[x] == x)
    return x;
  return par[x] = find(par[x], par);
}

void solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n), par(n), sizes(n);
  for(int i=0; i<n; ++i){
    scanf("%d", &a[i]);
    par[i] = i;
    sizes[i] = 1;
  }
  vector<set<int>> sets(n, set<int>());
  for(int i=0; i<m; i++){
    int l, r;
    scanf("%d%d", &l, &r);
    --l; --r;
    if(find(l, par) != find(r, par)){
      if(sizes[par[l]] < sizes[par[r]])
        swap(l, r);
      sizes[par[l]] += sizes[par[r]];
      par[find(r, par)] = find(l, par);
    }
  }
  for(int i=0; i<n; i++){
    //~ printf("i -> %d, par[i] -> %d\n", i, find(i, par));
    sets[find(i, par)].insert(a[i]);
  }
  for(int i=0; i<n; i++){
    int idx = find(i, par);
    assert(!sets[idx].empty());
    printf("%d ", *sets[idx].rbegin());
    sets[idx].erase(*sets[idx].rbegin());
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
