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

const int N = 2e6+5;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int par[N];

int find(int x){
  if(par[x] == x)
    return x;
  return par[x] = find(par[x]);
}

void solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> ans(m, 0);
  vector<int> a(m), b(m);
  for(int i=1; i<=n; i++){
    par[i] = i;
  }
  vector<int> leftover;
  for(int i=0; i<m; i++){
    scanf("%d%d", &a[i], &b[i]);
    if(find(a[i]) != find(b[i])){
      par[find(b[i])] = find(a[i]);
    } else{
      leftover.push_back(i);
    }
  }
  if(sz(leftover) == 3){
    set<int> setik;
    for(int i : leftover){
      setik.insert(a[i]);
      setik.insert(b[i]);
    }
    if(sz(setik) == 3){
      for(int i=1; i<=n; ++i){
        par[i] = i;
      }
      int edge = leftover[0];
      leftover.clear();
      par[b[edge]] = a[edge];
      for(int i=0; i<m; i++){
        if(i == edge) continue;
        if(find(a[i]) != find(b[i])){
          par[find(b[i])] = find(a[i]);
        } else {
          leftover.push_back(i);
        }
      }
      assert(sz(leftover) == 3);
    }
  }
  for(int i : leftover) ans[i] = 1;
  for(int i=0; i<m; i++)
    printf("%d", ans[i]);
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
