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

void solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> deg(n), odeg(n);
  vector<vector<int>> E(n);
  for(int i=0; i<m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    E[a].push_back(b);
    deg[b]++;
  }
  queue<int> Q;
  for(int i=0; i<n; i++){
    odeg[i] = deg[i];
    if(deg[i] == 0){
      Q.push(i);
    }
  }
  vector<int> v;
  while(!Q.empty()){
    int cur = Q.front();
    Q.pop();
    v.push_back(cur);
    for(int i : E[cur]){
      deg[i]--;
      if(deg[i] == 0){
        Q.push(i);
      }
    }
  }
  vector<int> dp(n, 1);
  for(int i=n-1; i>=0; i--){
    int mx = 0;
    for(int j : E[v[i]]){
      if(odeg[j] > 1)
        mx = max(mx, dp[j]);
    }
    dp[v[i]] = (sz(E[v[i]]) > 1 ? mx+1 : 1);
  }
  printf("%d\n", *max_element(all(dp)));
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
