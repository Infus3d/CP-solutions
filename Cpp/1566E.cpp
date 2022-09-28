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

int n, parity[N], parent[N], leaves;
vector<int> E[N];

void dfs(int x, int par){
  parent[x] = par;
  bool hasOne = false;
  for(int i : E[x]){
    if(i != par){
      dfs(i, x);
      if(parity[i] == 0)
        hasOne = true;
    }
  }
  if(hasOne == true) parity[x] = 1;
  else parity[x] = 0;
  if(sz(E[x]) == 1 && x != 1) leaves++;
}

void solve(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) E[i].clear();
  for(int i=1; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    E[a].push_back(b);
    E[b].push_back(a);
  }
  leaves = 0;
  dfs(1, 0);
  for(int i=1; i<=n; i++){
    int cnt = 0;
    for(int j : E[i]){
      if(j != parent[i])
        cnt += parity[j];
    }
    if(!parity[i] && sz(E[i]) > 1 && i > 1) cnt--;
    leaves -= cnt;
  }
  leaves += !parity[1]; //if root does not have a leaf (node with parity 0) after all arrangements
  printf("%d\n", leaves);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
