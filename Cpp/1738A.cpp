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
const int K = 101;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, dp[K][K][2];

int rec(int even, int odd, int par){
  if(even + odd == 0){
    return par^1;
  }
  if(even + odd == 1){
    if(even) return par^1;
    else return par;
  }
  if(dp[even][odd][par] != -1) return dp[even][odd][par];
  dp[even][odd][par] = 0;
  if(even > 0){
    int evenMove = 1;
    if(even > 1)
      evenMove &= rec(even-2, odd, par);
    if(odd > 0)
      evenMove &= rec(even-1, odd-1, par);
    if(evenMove){
      return dp[even][odd][par] = evenMove;
    }
  }
  if(odd > 0){
    int oddMove = 1;
    if(odd > 1)
      oddMove &= rec(even, odd-2, par^1);
    if(even > 0)
      oddMove &= rec(even-1, odd-1, par^1);
    if(oddMove){
      return dp[even][odd][par] = oddMove;
    }
  }
  return dp[even][odd][par];
}

void solve(){
  scanf("%d", &n);
  vector<int> a(n);
  int even = 0, odd = 0;
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    a[i] = (a[i] + (int)1e9) % 2;
    if(!a[i]) even++;
    else odd++;
  }
  for(int i=0; i<=even; i++){
    for(int j=0; j<=odd; j++){
      dp[i][j][0] = dp[i][j][1] = -1;
    }
  }
  printf("%s\n", rec(even, odd, 0) ? "Alice" : "Bob");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
