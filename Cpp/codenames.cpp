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

#define vi vector<int>
#define rep(i, a, b) for(int i = 0; i < (b); i++)

bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
	if (btoa[j] == -1) return 1;
	vis[j] = 1; int di = btoa[j];
	for (int e : g[di])
		if (!vis[e] && find(e, g, btoa, vis)) {
			btoa[e] = di;
			return 1;
		}
	return 0;
}
int dfsMatching(vector<vi>& g, vi& btoa) {
	vi vis;
	rep(i,0,sz(g)) {
		vis.assign(sz(btoa), 0);
		for (int j : g[i])
			if (find(j, g, btoa, vis)) {
				btoa[j] = i;
				break;
			}
	}
	return sz(btoa) - (int)count(all(btoa), -1);
}

vi cover(vector<vi>& g, int n, int m) {
	vi match(m, -1);
	int res = dfsMatching(g, match);
	vector<bool> lfound(n, true), seen(m);
	for (int it : match) if (it != -1) lfound[it] = false;
	vi q, cover;
	rep(i,0,n) if (lfound[i]) q.push_back(i);
	while (!q.empty()) {
		int i = q.back(); q.pop_back();
		lfound[i] = 1;
		for (int e : g[i]) if (!seen[e] && match[e] != -1) {
			seen[e] = true;
			q.push_back(match[e]);
		}
	}
	rep(i,0,n) if (!lfound[i]) cover.push_back(i);
	rep(i,0,m) if (seen[i]) cover.push_back(n+i);
	assert(sz(cover) == res);
	return cover;
}

int cnt[2];
int n;
vector<int> sides[2];

// void dfs(int x, int par, int t, vector<int> &vis, vector<vector<int>> &mat, vector<vector<int>> &g){
  // vis[x] = 1;
  // if(t == 0){
    // cnt[0]++;
    // g.push_back(vector<int>());
  // }
  // int cur = cnt[0]-1;
  // for(int i=1; i<=n; i++){
    // if(mat[x][i] == 1){
      // if(t == 0){
        // g[cur].push_back(cnt[1]);
          // cnt[1]++;
      // }
      // if(!vis[i]){
        // dfs(i, cur, t^1, vis, mat, g);
      // }
    // }
  // }
// }

void dfs(int x, int t, vector<int> &vis, vector<vector<int>> &mat){
  cnt[t]++;
  sides[t].push_back(x);
  vis[x] = 1;
  for(int i=1; i<=n; ++i){
    if(mat[x][i] == 1 && !vis[i]){
      dfs(i, t^1, vis, mat);
    }
  }
}

void solve(){
  cin >> n;
  string s;
  vector<vector<int>> mat(n+1, vector<int>(n+1, -1));
  vector<string> v;
  map<string, int> mk;
  for(int i=1; i<=n; i++){
    cin >> s;
    mk[s] = i;
    v.push_back(s);
  }
  
  for(int i=0; i<n; i++){
    s = v[i];
    int m = s.length();
    for(int u=0; u<m; u++){
      for(int v=u+1; v<m; v++){
        swap(s[u], s[v]);
        if(mk[s] != 0){
          mat[mk[s]][i+1] = 1;
          mat[i+1][mk[s]] = 1;
        }
        swap(s[u], s[v]);
      }
    }
  }
  
  vector<int> vis(n+1, 0);
  for(int i=1; i<=n; i++){
    if(vis[i] == 0){
      dfs(i, 0, vis, mat);
    }
  }
  
  map<int, int> vmap;
  vector<vector<int>> g;
  
  for(int i : sides[1]){
    vmap[i] = 1;
  }
  
  int vcnt = 0;
  
  for(auto it = vmap.begin(); it != vmap.end(); it++){
    it->ss = ++vcnt;
    // cout << it->ff << " " << it->ss << endl;
  }
  
  // for(auto it : vmap){
    // it.ss = ++vcnt;
    // cout << it.ff << " " << it.ss << endl;
  // }
  
  for(int i=1; i<=n; i++){
    if(vmap[i] == 0){
      // printf("Only at i = %d\n", i);
      if(true){
        g.push_back(vector<int>());
        for(int j=1; j<=n; j++){
          if(mat[i][j] == 1){
            g[sz(g)-1].push_back(vmap[j]-1);
            // printf("j-> %d, vmap[j]-> %d\n", j, vmap[j]);
          }
        }
      }
    }
  }
  
  // for(int i=0; i<sz(g); i++){
    // printf("i: %d : \n", i);
    // for(int j : g[i]){
      // printf("%d ", j);
    // }
    // puts("");
  // }
  
  if(cnt[0] == 0 || cnt[1] == 0){
    cout << n << endl;
    return;
  }
  
  vector<int> mincover = cover(g, cnt[0], cnt[1]);
  
  cout << n - sz(mincover) << endl;
}

int main(){
  // ios_base::sync_with_stdio(false);
  // cin.tie(0);
  int testcase = 1;
  while(testcase--){
    solve();
  }
  return 0;
}
