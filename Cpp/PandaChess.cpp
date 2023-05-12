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
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

vector<int> E[N];

void solve(){
  int n, m, d;
  scanf("%d%d%d", &n, &m, &d);
  vector<long long> a(m+1), b(m+1);
  map<long long, int> mk;
  for(int i=0; i<m; i++){
    scanf("%lld%lld", &a[i], &b[i]);
    mk[a[i]] = mk[b[i]] = 1;
  }
  vector<long long> t(n+1, 0);
  for(int i=1; i<=n; i++){
    scanf("%lld", &t[i]);
  }
  int cnt = 0;
  for(auto &i : mk) i.ss = ++cnt;
  assert(cnt == n);
  
  map<pair<int, int>, bool> seen;
  vector<int> deg(n+1, 0);
  for(int i=0; i<m; i++){
    int x = mk[a[i]], y = mk[b[i]];
    if(!seen[{x, y}]){
      E[y].push_back(x);
      deg[x]++;
      seen[{x, y}] = true;
    }
  }
  
  queue<int> Q;
  for(int i=1; i<=n; i++){
    if(deg[i] == 0){
      Q.push(i);
    }
  }
  
  assert(sz(Q) == 1);
  vector<int> topOrder;
  while(!Q.empty()){
    int u = Q.front(); Q.pop();
    topOrder.push_back(u);
    for(int v : E[u]){
      deg[v]--;
      if(deg[v] == 0){
        Q.push(v);
      }
    }
  }
  assert(sz(topOrder) == n);
  reverse(all(topOrder));
  
  vector<int> topIdx(n+1, -1);
  for(int i=0; i<n; i++){
    topIdx[topOrder[i]] = i+1;
  }
  
  vector<int> dp;
  for(int i=1; i<=n; i++){
    if(mk[t[i]] == 0) continue;
    int x = topIdx[mk[t[i]]];
    auto it = lower_bound(dp.begin(), dp.end(), x);
    if(it == dp.end()){
      dp.push_back(x);
    } else {
      *it = x;
    }
  }
  
  printf("%d\n", 2*(n - (int)dp.size()));
}


int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
