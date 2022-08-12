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

int n, k, q;
ll a[N], b[N];
char s[N];

void solve(){
  scanf("%d%d%d", &n, &k, &q);
  scanf("%s", s+1);
  
  vector<ll> len(k+1);
  len[0] = n;
  for(int i=1; i<=k; i++){
    scanf("%lld%lld", &a[i], &b[i]);
    len[i] = len[i-1] + (b[i]-a[i]+1);
  }
  
  while(q--){
    long long x; 
    scanf("%lld", &x);
    
    while(x > n){
      int p = 0;
      while(p < k && len[p] < x) p++;
      x = (x-len[p-1]-1 + a[p]);
    }
    
    assert(x <= n);
    printf("%c\n", s[x]);
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
