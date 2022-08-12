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

const int N = 30001;
const int K = 250;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int a, n, d, dp[N][K*2], w[N];

int rec(int pos, int jump){
  if(jump < 1 || pos >= N) return 0;
  int k = jump-d+250;
  //~ printf("pos:%d, jump:%d, k:%d\n", pos, jump, k);
  int &ret = dp[pos][k];
  if(~ret) return ret;
  ret = w[pos] + max(max(rec(pos+jump-1, jump-1), rec(pos+jump, jump)), rec(pos+jump+1, jump+1));
  return ret;
}

void solve(){
  memset(dp, -1, sizeof (dp));
  scanf("%d%d", &n, &d);
  for(int i=1; i<=n; i++){
    scanf("%d", &a);
    w[a]++;
  }
  printf("%d\n", rec(d, d));
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
