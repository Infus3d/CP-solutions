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

const int N = 3e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

ll n, a[N], b[N], aa[N], bb[N];
vector<ll> v1, v2;
ll cur1, cur2, ans, tot, d[N][2], f[N][2];

void solve(){
  scanf("%lld", &n);
  for(int i=1; i<=n; i++) scanf("%lld", &a[i]), tot += a[i];
  for(int i=1; i<=n; i++) scanf("%lld", &b[i]), tot += b[i];
  
  for(int i=1; i<=n; i++){
    d[i][0] = d[i-1][1] + (1LL * (2*(i-1)) * b[i]) + (1LL * (2*(i-1)+1) * a[i]);
    d[i][1] = d[i-1][0] + (1LL * (2*(i-1)) * a[i]) + (1LL * (2*(i-1)+1) * b[i]);
  }
  for(int i=n; i>=1; i--){
    aa[i] = a[i] + aa[i+1];
    bb[i] = b[i] + bb[i+1];
    f[i][0] = f[i+1][0] - aa[i+1] - bb[i+1] + (b[i] * ((n)*2-1)) + (a[i] * ((i-1)*2));
    f[i][1] = f[i+1][1] - aa[i+1] - bb[i+1] + (a[i] * ((n)*2-1)) + (b[i] * ((i-1)*2));
  }
  
  for(int i=0; i<=n; i++)
    umax(ans, d[i][i%2] + f[i+1][i%2]);
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
