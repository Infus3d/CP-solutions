/*
For a query (u, v), the answer is ( n + (dist(u, v) choose 2) ). You can get n different
subsets of nodes by just choosing 1 subtree to be u, and second subtree to be any node in the tree.
You can get additional (dist(u, v) choose 2) sets for every two nodes on the path from u to v.
There are many ways to find the distance between two nodes u and v (for Q queries). One of them is
through LCA (Least Common Ancestor) which is shown below. It uses binary jumping. Please google a tutorial
to learn how to find the distance between two nodes using LCA.

Runtime O((n+q) * log(n))
*/
#include "bits/stdc++.h"

using namespace std;

const int N = 2e5+1;
const int K = 18;

int n, q;
int lvl[N], P[N][K];

vector<int> E[N];

void dfs(int u, int par){
	lvl[u] = lvl[par] + 1;
	P[u][0] = par;
	for(int v : E[u]){
		if(v != par){
			dfs(v, u);
		}
	}
}

void build_lca(){
	for(int j=1; j<K; j++){
		for(int i=1; i<=n; i++){
			if(P[i][j-1] > 0){
				P[i][j] = P[P[i][j-1]][j-1];
			}
		}
	}
}

int lca(int a, int b){
	if(lvl[a] < lvl[b]){
		swap(a, b);
	}
	for(int i=17; i>=0; i--){
		if(lvl[a] - (1<<i) >= lvl[b]){
			a = P[a][i];
		}
	}
	if(a == b){
		return a;
	}
	for(int i=17; i>=0; i--){
		if(P[a][i] > 0 && P[a][i] != P[b][i]){
			a = P[a][i];
			b = P[b][i];
		}
	}
	return P[a][0];
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i=0; i<n-1; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	dfs(1, 0);
	build_lca();
	while(q--){
		int a, b;
		scanf("%d%d", &a, &b);
		int anc = lca(a, b);
		int dist = lvl[a] + lvl[b] - 2*lvl[anc];
		long long ans = n + (1LL * dist * (dist+1)) / 2LL;
		printf("%lld\n", ans);
	}
	return 0;
}
