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
  vector<long long> a(n);
  for(int i=0; i<n; i++){
    scanf("%lld", &a[i]);
  }
  vector<long long> b(n-1);
  for(int i=0; i<n-1; i++){
    scanf("%lld", &b[i]);
  }
  long long coins = 0, ans = (int)1e9, moves = 0;
  for(int i=0; i<n; i++){
    long long comitting = (max(0ll, m - coins) + a[i] - 1) / a[i];
    ans = min(ans, moves + comitting);
    if(i == n-1 || b[i] >= m) break;
    long long skipping = (max(0ll, b[i] - coins) + a[i] - 1) / a[i];
    coins += skipping * a[i];
    coins -= b[i];
    moves += skipping + 1;
  }
  printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
