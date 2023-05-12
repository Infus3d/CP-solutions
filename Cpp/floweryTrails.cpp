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

int n, m;
int dist[N], vis[N];
vector<pair<int, int>> E[N], R[N];

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    E[a].push_back({b, c});
    E[b].push_back({a, c});
  }
  for(int i=0; i<n; i++){
    dist[i] = MOD;
    vis[i] = 0;
  }
  set<pair<int, int>> setik;
  setik.insert({0, 0});
  dist[0] = 0;
  while(!setik.empty()){
    auto [d, u] = *setik.begin();
    setik.erase(setik.begin());
    if(vis[u]) continue;
    vis[u] = 1;
    for(auto [v, w] : E[u]){
      if(dist[v] > d + w){
        R[v].clear();
        R[v].push_back({u, w});
        dist[v] = d + w;
        setik.insert({dist[v], v});
      } else if(dist[v] == d + w){
        R[v].push_back({u, w});
      }
    }
  }
  for(int i=0; i<n; i++) vis[i] = 0;
  queue<int> Q;
  Q.push(n-1);
  vis[n-1] = 1;
  int ans = 0;
  // printf("The shortest distance: %d\n", dist[n-1]);
  while(!Q.empty()){
    int u = Q.front();
    Q.pop();
    // printf("Cur Node: %d\n", u);
    for(auto [v, w] : R[u]){
      // printf("Neighbor: %d, cost: %d\n", v, w);
      if(vis[v] == 0){
        vis[v] = 1;
        Q.push(v);
      }
      ans += w;
    }
  }
  printf("%d\n", ans*2);
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
