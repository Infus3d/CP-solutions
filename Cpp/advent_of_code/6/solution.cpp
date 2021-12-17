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

void solve(){
  int n;
  vector<int> v;
  while(!feof(stdin) && scanf("%d,", &n)) v.pb(n);
  v.pop_back();
  
  ll a[300], ans = v.size();
  memset(a, 0, sizeof(a));
  for(int i : v)  a[i]++;
  for(int i=0; i<256; i++){
    ans += a[i];
    a[i+9] += a[i];
    a[i+7] += a[i];
  }
  printf("%lld\n", ans);
}

int main(){
  ll tot = 0;
  printf("%lld\n", tot);
  int testcase = 1;
  freopen("input.txt", "r", stdin);
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
