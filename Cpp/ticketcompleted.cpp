/*
You are given a graph, and two vertices a and b. You need to find the probability
that a and b are connected, or in other words, the probability that they are in the
same connected component. Let there be k connected components and let size[i] be the
size of the connected component i. The answer is then:
( \sum (size[i] choose 2) ) / (n choose 2)
or
( \sum (size[i] * (size[i-1] - 1) / 2) ) / (n * (n-1) / 2)
*/
#include "bits/stdc++.h"

using namespace std;

const int N = 1e5+1;

int n, m, cnt, vis[N];
vector<int> E[N];

void dfs(int u){
	++cnt;
	vis[u] = 1;
	for(int v : E[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	long long ans = 0;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			cnt = 0;
			dfs(i);
			ans += 1LL * cnt * (cnt - 1) / 2LL;
		}
	}
	long long total = 1LL * n * (n-1) / 2LL;
	printf("%.6lf\n", (double)ans / total);
	
	return 0;
}
