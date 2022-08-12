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

const int N = 1e5+2;
const int K = 4e4;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, d[N];

#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

void solve(){
  scanf("%d", &n);
  ll sum = 0LL;
  for(int i=1; i<=n; i++) scanf("%d", &d[i]), sum += d[i];
  ll l = 0, r = (ll)(1e14);
  while(l + 1 < r){
    ll md = (l + r) / 2LL;
    if(md * (n-1) >= sum) r = md;
    else l = md;
  }
  dbg(l, r, sum);
  printf("%lld\n", r);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
