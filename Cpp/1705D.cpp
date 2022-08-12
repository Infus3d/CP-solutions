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
char s[N], t[N];

void solve(){
  scanf("%d", &n);
  scanf("%s%s", s, t);
  vector<pii> a, b;
  for(int i=0; i<n; i++){
    if(s[i] == '1'){
      if(!i || s[i-1] == '0')
        a.push_back({i, i});
      if(i == n-1 || s[i+1] == '0')
        a.back().second = i;
    }
  }
  for(int i=0; i<n; i++){
    if(t[i] == '1'){
      if(!i || t[i-1] == '0')
        b.push_back({i, i});
      if(i == n-1 || t[i+1] == '0')
        b.back().second = i;
    }
  }
  
  if(s[0] != t[0] || s[n-1] != t[n-1] || sz(a) != sz(b)){
    puts("-1");
    return;
  }
  
  long long ans = 0;
  for(int i=0; i<sz(a); i++){
    ans += abs(a[i].ff - b[i].ff);
    ans += abs(a[i].ss - b[i].ss);
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
