#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define db puts("*****")
#define mid(x , y) ((x+y)>>1)
#define y1 your_name_engraved_herein

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

void solve(){
    int n; scanf("%d", &n);
    set<int> setikx, setiky;
    vector<int> x(n), y(n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &x[i], &y[i]);
        setikx.insert(x[i]);
        setiky.insert(y[i]);
    }
    int xn = sz(setikx);
    int yn = sz(setiky);
    vector<int> idx(501), idy(501);
    int px = 0, py = 0;
    for(int i : setikx){
        idx[i] = px++;
    }
    for(int i : setiky){
        idy[i] = py++;
    }
    vector<vector<int>> g(xn, vector<int>());
    for(int i=0; i<n; i++){
        g[idx[x[i]]].push_back(idy[y[i]]);
    }
    vector<int> btoa(yn, -1);
    int matching = hopcroftKarp(g, btoa);
    
    if(xn == yn && matching == xn){
        puts("Slavko");
    } else {
        puts("Mirko");
    }
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
