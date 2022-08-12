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
  int n; scanf("%d", &n);
  vector<int> a(n), lef(n), rig(n);
  vector<vector<int>> teibl(n+1, vector<int>(n+1));
  for(int i=0; i<n; i++) scanf("%d", &a[i]);
  for(int i=0; i<n; i++){
    for(int j=1; j<=n; j++){
      if(a[i] < j)
        teibl[j][i]++;
      if(i > 0)
        teibl[j][i] += teibl[j][i-1];
    }
  }
  
  ll ans = 0LL;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      int b = 0, c = 0;
      if(i > 0)
        c = teibl[a[j]][i-1];
      b = teibl[a[i]][n-1] - teibl[a[i]][j];
      
      ans += b*c;
    }
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
