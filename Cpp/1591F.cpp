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
 
const int N = 2e3+2;
const int K = 1e3+2;
const int MOD = 998244353;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
 
ll x;
ll n, k, p;
char s[N], ans[N*N];
 
void solve(){
  vector<pair<ll, int>> v; v.pb({0LL, 0});
  scanf("%lld%lld%lld%s", &n, &k, &x, s);
  for(int i=0; i<n; i++){
    if(s[i] != '*') continue;
    if(i > 0 && s[i-1] == '*')
      v[sz(v)-1].ff += k;
    else
      v.pb({k, i});
  }
  
  int m = sz(v);
  int ii = -1, jj = 0;
  ll tot = 1LL;
  for(int i=m-1; i>=1; i--){
    for(int j=0; j<=v[i].ff; j++){
      if((j+1)*tot >= x){
        ii = i;
        break;
      }
    }
    if(~ii) break;
    tot *= v[i].ff+1;
  }
  
  //~ printf("ii:%d, jj:%d, v[0]:%lld\n", ii, jj, v[0].ff);
  //~ printf("tot:%lld\n", tot);
  
  for(int i=ii; i<m; i++){
    if(i > 0){
      for(int j=(i == ii ? 0 : v[i-1].ss); j<v[i].ss; j++)
        if(s[j] == 'a')
          printf("a");
    }
    
    jj = 0;
    for(int j=0; j<=v[i].ff; j++){
      if((j+1)*tot >= x){
        jj = j;
        break;
      }
    }
    
    x -= 1LL * jj * tot;
    if(i < m-1) tot /= v[i+1].ff+1;
    for(int j=0; j<jj; j++)
      printf("b");
  }
  //~ while(x > 1) { printf("b"); x--; }
  if(m){
    for(int j=v[m-1].ss; j<n; j++)
      if(s[j] == 'a')
        printf("a");
  }
  puts("");
  //~ printf("%lld\n", x);
}
 
int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
