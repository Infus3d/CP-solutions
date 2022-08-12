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

const int N = 1e2+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m, a, b, taken[N];
pii rest[N], order[N];

void solve(){
  int ans = 0;
  memset(taken, 0, sizeof(taken));
  for(int i=1; i<=n; i++) cin >> rest[i].ff >> rest[i].ss;
  for(int i=1; i<=m; i++) cin >> order[i].ff >> order[i].ss;
  for(int i=1; i<=m; i++){
    int mn = MOD, ind = -1;
    for(int j=1; j<=n; j++){
      if(!taken[j] && umin(mn, abs(rest[j].ff - order[i].ff) + abs(rest[j].ss - order[i].ss)))
        ind = j;
    }
    assert(ind != -1);
    taken[ind] = 1;
    ans += mn;
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(cin >> n >> m){
    solve();
  }
  return 0;
}
