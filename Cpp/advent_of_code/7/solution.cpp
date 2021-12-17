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

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int a, mx;
vector<int> v;

void solve(){
  freopen("input.txt", "r", stdin);
  while(!feof(stdin) && scanf("%d,", &a)) v.pb(a), umax(mx, a);
  v.pop_back();
  
  ll ans = 1e18;
  for(int i=0; i<=mx; i++){
    ll cur = 0LL;
    for(int j : v){
      int b = abs(j-i);
      cur += 1LL*b*(b+1)/2;
    }
    umin(ans, cur);
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
