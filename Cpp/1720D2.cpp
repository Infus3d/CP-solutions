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
const int K = 29;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, d[N], cnt;
int trie[N*(K+1)][2];
int dp[N*K][2];

int find(int x, int idx){
  int cur = 0;
  int ret = 0;
  for(int i=K; i>=0; i--){
    int curbit = (x>>i)&1;
    if(trie[cur][curbit^1] != 0){
      int node = trie[cur][curbit^1];
      ret = max(ret, dp[node][(idx>>i)&1]);
    }
    if(trie[cur][curbit] == 0) break;
    cur = trie[cur][curbit];
  }
  return ret;
}

void add(int x, int idx, int val){
  int cur = 0;
  for(int i=K; i>=0; i--){
    int curbit = (x>>i)&1;
    if(trie[cur][curbit] == 0)
      trie[cur][curbit] = ++cnt;
    cur = trie[cur][curbit];
    dp[cur][(idx>>i)&1] = max(dp[cur][(idx>>i)&1], val);
  }
}

void solve(){
  scanf("%d", &n);
  for(int i=0; i<=cnt; i++){
    trie[i][0] = trie[i][1] = 0;
    dp[i][0] = dp[i][1] = 0;
  }
  cnt = 0;
  int ans = 0;
  for(int i=0; i<n; i++){
    scanf("%d", &d[i]);
    int themax = find(d[i] ^ i, i);
    add(d[i] ^ i, d[i], themax+1);
    ans = max(ans, themax+1);
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
