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

const int N = 4e6+2;
const int K = 22;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, d[N];
int dp[(1<<K)], track[(1<<K)];

void solve(){
  scanf("%d", &n);
  int lim = (1<<K)-1;
  for(int i=1; i<=n; i++){
    scanf("%d", &d[i]);
    dp[d[i]] = 1;
    track[d[i]] = d[i];
    assert(d[i] <= lim);
  }
  for(int i=0; i<K; i++){
    for(int mask=1; mask<=lim; mask++){
      if(((mask>>i)&1) && dp[mask^(1<<i)] > 0){
        dp[mask] += dp[mask^(1<<i)];
        track[mask] = track[mask^(1<<i)];
      }
    }
  }
  for(int i=1; i<=n; i++){
    int val = d[i] ^ lim;
    assert(val <= lim);
    if(dp[val] == 0) printf("%d ", -1);
    else printf("%d ", track[val]);
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
