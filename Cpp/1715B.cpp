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
  long long n, k, b, s;
  scanf("%lld%lld%lld%lld", &n, &k, &b, &s);
  long long mini = k*b, maxi = k*b + n*(k-1);
  if(s < mini || maxi < s){
    puts("-1");
    return;
  }
  s -= k*b;
  vector<long long> ans(n, 0);
  ans[0] = k*b;
  for(int i=0; i<n; i++){
    ans[i] += min(k-1, max(0LL, s));
    s -= (k-1);
  }
  for(long long i : ans) printf("%lld ", i);
  puts("");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
