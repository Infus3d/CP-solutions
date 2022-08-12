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
  vector<pii> goblin;
  for(int i=0; i<n; i++){
    int a, b; scanf("%d%d", &a, &b);
    goblin.pb({a, b});
  }
  
  int m; scanf("%d", &m);
  vector<pair<int, pii>> sprink;
  for(int i=0; i<m; i++){
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    sprink.push_back({c, {a, b}});
  }
  
  int ans = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int x = sprink[j].ss.ff - goblin[i].ff;
      int y = sprink[j].ss.ss - goblin[i].ss;
      int r = sprink[j].ff;
      if(x*x + y*y <= r*r){
        ans++;
        break;
      }
    }
  }
  printf("%d\n", n-ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
