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

int n, m, d[N];
long long k;

bool fine(int x, vector<pair<int, int>> &v){
  vector<vector<int>> E(n+1);
  vector<int> deg(n+1);
  for(int i=0; i<m; i++){
    auto [a, b] = v[i];
    if(max(d[a], d[b]) <= x){
      E[a].push_back(b);
      deg[b]++;
    }
  }
  queue<int> Q;
  for(int i=1; i<=n; i++){
    if(deg[i] == 0){
      Q.push(i);
    }
  }
  vector<int> sorted;
  while(!Q.empty()){
    int tr = Q.front();
    Q.pop();
    sorted.push_back(tr);
    for(int i : E[tr]){
      deg[i]--;
      if(deg[i] == 0){
        Q.push(i);
      }
    }
  }
  vector<int> dp(n+1, 0);
  for(int i : sorted){
    for(int j : E[i])
      umax(dp[j], dp[i]+1);
  }
  int maxi = *max_element(all(dp));
  if(sz(sorted) != n || maxi >= k-1) return true;
  return false;
}

void solve(){
  scanf("%d%d%lld", &n, &m, &k);
  vector<int> ordered;
  for(int i=1; i<=n; i++){
    scanf("%d", &d[i]);
    ordered.push_back(d[i]);
  }
  vector<pair<int, int>> v;
  for(int i=0; i<m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    v.push_back({a, b});
  }
  sort(all(ordered));
  int l = -1, r = n-1;
  while(l + 1 < r){
    //~ printf("l->%d, r->%d, ordered[mid(l, r)]:%d\n", l, r, ordered[mid(l, r)]);
    if(fine(ordered[mid(l, r)], v))
      r = mid(l, r);
    else
      l = mid(l, r);
  }
  if(!fine(ordered[r], v)) puts("-1");
  else printf("%d\n", ordered[r]);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
