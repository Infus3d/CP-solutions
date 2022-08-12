#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <ll , ll>
#define mid(x , y) ((x+y)>>1)
#define all(x)	x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, m, a, b;
vector<pair<int, ll>> E[N];
set<pair<ll, int>> setik;
ll cost[N], c;

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=m; i++){
    scanf("%d%d%lld", &a, &b, &c);
    E[a].push_back({b, 2*c});
    E[b].push_back({a, 2*c});
  }
  for(int i=1; i<=n; i++){
    scanf("%lld", &cost[i]);
    setik.insert({cost[i], i});
  }
  
  while(!setik.empty()){
    int cur = setik.begin()->second;
    setik.erase(setik.begin());
    
    for(auto i : E[cur]){
      if(cost[i.ff] > cost[cur] + i.ss){
        setik.erase({cost[i.ff], i.ff});
        cost[i.ff] = cost[cur] + i.ss;
        setik.insert({cost[i.ff], i.ff});
      }
    }
  }
  
  for(int i=1; i<=n; i++)
    printf("%lld ", cost[i]);
  puts("");
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
