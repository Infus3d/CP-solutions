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

const int N = 3e7+2;
const int K = 1e5+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int a[N], b[200], n, m, q, ans[K];
pii c[K];

void solve(){
  scanf("%d%d%d", &n, &m, &q);
  for(int i=1; i<=m; i++) scanf("%d", &b[i]), a[b[i]]++;
  for(int i=1; i<=q; i++) scanf("%d", &c[i].ff), c[i].ss = i;
  
  int cnt = 0;
  for(int i=m+1; i<=n; i++){
    b[i-cnt-m] = (b[i-cnt-m] + b[(i-cnt-m+1) == m+1 ? 1 : (i-cnt-m+1)]) % ((int)3e7);
    a[b[i-cnt-m]]++;
    if(i % m == 0) cnt += m;
  }
  
  int p = -1, cur = 0;
  sort(c+1, c+q+1);
  for(int i=1; i<=q; i++){
    int t = c[i].ff-1;
    while(p < (int)3e7 && cur <= t){
      p++;
      cur += a[p];
    }
    ans[c[i].ss] = p;
  }
  
  for(int i=1; i<=q; i++)
    printf("%d\n", ans[i]);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
