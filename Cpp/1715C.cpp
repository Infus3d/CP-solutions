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
  vector<int> a(n+1);
  long long ans = 0;
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    long long d = n-i+1;
    ans += (d * (d+1)) / 2;
  }
  for(int i=2; i<=n; i++){
    if(a[i] == a[i-1]){
      ans -= (long long)(i-1) * (n-i+1);
    }
  }
  while(m--){
    int x, val;
    scanf("%d%d", &x, &val);
    if(a[x] != val){
      if(x > 1 && a[x] != a[x-1] && val == a[x-1]){
        ans -= (long long)(x-1) * (n-x+1);
      }
      if(x > 1 && a[x] == a[x-1] && val != a[x-1]){
        ans += (long long)(x-1) * (n-x+1);
      }
      if(x < n && a[x] != a[x+1] && val == a[x+1]){
        ans -= (long long)(x) * (n-x);
      }
      if(x < n && a[x] == a[x+1] && val != a[x+1]){
        ans += (long long)(x) * (n-x);
      }
    }
    a[x] = val;
    printf("%lld\n", ans);
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
