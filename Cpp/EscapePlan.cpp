#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
// #define ll long long
#define db puts("*****")
// #define sz(x) int(x.size())
// #define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
// #define all(x)	x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

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

const int eps = 0.000001;

bool solve(int testcase){
    int n, m; scanf("%d", &n);
    if(n == 0){
        return false;
    }
    vector<pair<double, double>> robots(n);
    for(int i=0; i<n; i++){
        scanf("%lf %lf", &robots[i].ff, &robots[i].ss);
    }
    scanf("%d", &m);
    vector<pair<double, double>> holes(m);
    for(int i=0; i<m; i++){
        scanf("%lf %lf", &holes[i].ff, &holes[i].ss);
    }
    printf("Scenario %d\n", testcase);
    for(int sec=5; sec<=20; sec*=2){
        vector<vector<int>> g(n, vector<int>());
        vector<int> btoa(m, -1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                double xd = fabs(robots[i].ff - holes[j].ff);
                double yd = fabs(robots[i].ss - holes[j].ss);
                double dist = xd * xd + yd * yd;
                double maxDist = 10.0 * sec;
                if((maxDist * maxDist) - dist > -eps){
                    g[i].push_back(j);
                }
            }
        }
        int matching = hopcroftKarp(g, btoa);
        printf("In %d seconds %d robot(s) can escape\n", sec, matching);
    }
    return true;
}

int main(){
    // int testcase = 1;
    // scanf("%d", &testcase);
    for(int i=1; i<=10; i++){
        if(!solve(i)){
            break;
        }
    }
    return 0;
}
