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

int n;
ll m;
pii p[N];

bool ok(ll x){
  ll sum = 0;
  for(int i=1; i<=n; i++){
    if(x * p[i].ff > p[i].ss)
      sum += (x * p[i].ff) - p[i].ss;
    if(sum >= m)
      return true;
  }
  return false;
}

void solve(){
  scanf("%d%lld", &n, &m);
  for(int i=1; i<=n; i++)
    scanf("%d%d", &p[i].ff, &p[i].ss);
  
  ll l = 0, r = (ll)4e9+1;
  while(l + 1 < r){
    if(ok(mid(l, r))) r = mid(l, r);
    else l = mid(l, r);
  }
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
