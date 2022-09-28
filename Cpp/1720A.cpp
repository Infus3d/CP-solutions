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
  long long a, b, c, d;
  scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
  if(min(a, c) == 0){
    if(a == 0 && c == 0) puts("0");
    else puts("1");
  }
  else{
    long long gcd1 = __gcd(a, b);
    long long gcd2 = __gcd(c, d);
    a /= gcd1, b /= gcd1;
    c /= gcd2, d /= gcd2;
    if(a == c && b == d) puts("0");
    else if(d % b == 0 && (a * (d/b)) % c == 0) puts("1");
    else if(b % d == 0 && (c * (b/d)) % a == 0) puts("1");
    else puts("2");
  }
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
