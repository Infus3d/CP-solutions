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

int n, dp[N];
vector<int> E[N];

void dfs(int x, int par){
  int cnt = 0, tot = 0;
  for(int i : E[x]){
    if(i != par){
      dfs(i, x);
      if(dp[i] > 0){
        cnt++;
      }
      dp[x] += dp[i];
      tot++;
    }
  }
  if(sz(E[x]) > 1){
    dp[x] += (max(0, tot-cnt-1));
  }
}

void solve(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    E[i].clear();
    dp[i] = 0;
  }
  for(int i=1; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    E[a].push_back(b);
    E[b].push_back(a);
  }
  if(n == 1){
    puts("0");
    return;
  }
  int root = -1;
  for(int i=1; i<=n; i++){
    if(sz(E[i]) > 2)
      root = i;
  }
  if(root == -1){
    puts("1");
    return;
  }
  dfs(root, 0);
  printf("%d\n", dp[root]);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
