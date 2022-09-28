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

/*from KACTL: 
https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
* */
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
/*
 * Dynamic CHT, an overkill for this problem but it works!
 * */
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

void dijkstra(vector<vector<pii>> &E, vector<long long> &dist){
  int n = E.size()-1;
  vector<bool> used(n+1, false);
  priority_queue<pair<long long, int>> Q;
  for(int i=1; i<=n; i++){
    Q.push({-dist[i], i});
  }
  while(!Q.empty()){
    int u = Q.top().second;
    Q.pop();
    if(used[u]){
      continue;
    }
    used[u] = true;
    for(auto [v, w] : E[u]){
      if(dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        Q.push({-dist[v], v});
      }
    }
  }
}

void solve(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector<vector<pii>> E(n+1);
  for(int i=0; i<m; i++){
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    E[u].push_back({v, w});
    E[v].push_back({u, w});
  }
  vector<long long> dist(n+1, (long long)1e18);
  dist[1] = 0;
  dijkstra(E, dist);
  for(int i=0; i<k; i++){
    LineContainer cht;
    for(int j=1; j<=n; j++){
      cht.add(2*j, -(dist[j] + (1LL*j*j)));
    }
    for(int j=1; j<=n; j++){
      dist[j] = -cht.query(j) + (1LL*j*j);
      /* Above we don't need to do dist[j] = min(dist[j], -cht.query(j)+(1ll*j*j));
       * because the j'th line is already in CHT so if min of the above two was to be dist[j]
       * then -cht.query(j) will inevitably return (dist[j]+(1ll*j*j) - 2*j*j).
       * */
    }
    dijkstra(E, dist);
  }
  for(int i=1; i<=n; i++){
    printf("%lld ", dist[i]);
  }
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
