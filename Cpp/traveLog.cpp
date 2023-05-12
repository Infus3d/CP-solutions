#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <ll , ll>
#define piii pair<pii, int>
#define mid(x , y) ((x+y)>>1)
#define all(x)	x.begin(),x.end()
#define y1 your_name_engraved_herein
#define INF 1000000000000000005

using namespace std;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n,m,d;

vector<vector<pii> > g;
vector<ll> t,dist;
vector<pii> parent;
vector<int> path;
piii x;
pii v;

int dijkstra(){
  ll di,u, ite;
  dist.assign(n + 1, INF);
  vector<ll> cont(n + 1, 0);
  dist[1] = 0;
  priority_queue<piii, vector<piii>, greater<piii> > pq;
  
  pq.push(make_pair(make_pair(0, 1), t[0] == 0));
  cont[1] = 1LL;
  
  while(!pq.empty()){
    x = pq.top();pq.pop();
    
    u = x.ff.ss;
    di = x.ff.ff;
    ite = x.ss;
    
    if(di > dist[u]) continue;
    
    for(int i = 0; i < (int) g[u].size(); i++){
      v = g[u][i];
      if(v.ss < 0) continue;
      if(dist[u] + v.ss < dist[v.ff] && dist[u] + v.ss <= t[ite] ){
        dist[v.ff] = dist[u] + v.ss;
        parent[v.ff] = {u, i};
        pq.push(make_pair(make_pair(dist[v.ff], v.ff), ite + (int)(dist[u] + v.ss == t[ite])));
        cont[v.ff] = cont[u];
      }else if(dist[u] + v.ss == dist[v.ff] && dist[u] + v.ss <= t[ite] ){
        cont[v.ff]++;
      }
    }
  }
  return cont[n];
}

void solve(){
  
  cin >> n >> m >> d;
  g.assign(n + 1, vector<pii> ());
  t.assign(d, 0);
  parent.assign(n + 1, pii());
  
  int u,v;
  ll h;
  
  for(int i = 0; i < m; i++){
    cin >> u >> v >> h;
    
    g[u].push_back(make_pair(v,h));
  }
  
  for(int i = 0; i < d; i++){
    cin >> t[i];
  }
  
  sort(t.begin(), t.end());
  
  t.push_back(INF);
  
  int res = dijkstra();
  
  if(res == 1 && dist[n] >= t[d - 1]){
    path.push_back(n);
    v = n;
    while(v != 1){
      path.push_back(parent[v].ff);
      v = parent[v].ff;
    }
    
    reverse(path.begin(), path.end());
    
    cout << (int)path.size() << endl;
    for(int i : path){
      cout << i << endl;
    }
  }else{
    cout << (int)(res > 0 && dist[n] >= t[d-1]) << endl;
  }
}

int main(){
  int testcase = 1;
  //scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
