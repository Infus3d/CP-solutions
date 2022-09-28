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
  int n, k;
  scanf("%d%d", &n, &k);
  vector<long long> a(n+1), b(n+1);
  for(int i=1; i<=n; i++){
    scanf("%lld", &a[i]);
  }
  long long curSum = 0, cnt = 0, ans = 0;
  for(int i=n; i>=1; i--){
    curSum -= cnt;
    cnt -= b[i];
    a[i] -= curSum;
    if(a[i] > 0){
      if(i < k){
        long long moves = (a[i] + (i-1)) / i;
        ans += moves;
        cnt += moves;
        curSum += moves * i;
      }
      else{
        long long moves = (a[i] + (k-1)) / k;
        ans += moves;
        cnt += moves;
        curSum += moves * k;
        b[i-k] += moves;
      }
    }
  }
  printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
