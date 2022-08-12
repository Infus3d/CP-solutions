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

ll a, b;

void solve(){
  scanf("%lld%lld", &a, &b);
  ll ans = 0;
  for(int i=a; i<=b; i++){
    int sum = 0, prod = 1, x = i;
    while(x > 0){
      sum += x%10;
      prod *= x%10;
      x /= 10;
    }
    if(prod % sum == 0)
      ans++;
  }
  printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int tt=1; tt<=testcase; tt++){
    printf("Case #%d: ", tt);
    solve();
  }
  return 0;
}
