#include "bits/stdc++.h"

using namespace std;

int main(){
	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);
	vector<vector<pair<int, int>>> E(n+1, vector<pair<int, int>>());
	for(int i=0; i<m; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		E[a].push_back({b, c});
		E[b].push_back({a, c});
	}
	int src, dest;
	scanf("%d%d", &src, &dest);
	int k; scanf("%d", &k);
	vector<int> spiders(k);
	for(int i=0; i<k; i++){
		scanf("%d", &spiders[i]);
	}
	
	auto ok = [&](int lim){
		set<pair<int, int>> pq;
		vector<int> dist(n+1, 2e9+7);
		vector<bool> badnode(n+1, false);
		for(int i=0; i<k; i++){
			dist[spiders[i]] = 0;
			pq.insert({dist[spiders[i]], spiders[i]});
		}
		while(!pq.empty()){
			auto [w, u] = *pq.begin();
			pq.erase(pq.begin());
			if(badnode[u]) continue;
			if(w >= lim) break;
			badnode[u] = true;
			for(auto [v, c] : E[u]){
				if(dist[v] > w + c){
					dist[v] = w + c;
					pq.insert({dist[v], v});
				}
			}
		}
		if(badnode[src]){
			return false;
		}
		
		pq.clear();
		dist.assign(n+1, 2e9+7);
		dist[src] = 0;
		pq.insert({dist[src], src});
		vector<bool> vis(n+1, false);
		while(!pq.empty()){
			auto [w, u] = *pq.begin();
			pq.erase(pq.begin());
			if(vis[u]) continue;
			vis[u] = true;
			for(auto [v, c] : E[u]){
				if(dist[v] > (w + c) && !badnode[v]){
					dist[v] = w + c;
					pq.insert({dist[v], v});
				}
			}
		}
		return vis[dest] && (dist[dest] <= t);
	};
	
	int l = 0, r = 2e9+1;
	while(l+1 < r){
		int mid = (l + r) / 2;
		if(ok(mid)){
			l = mid;
		} else {
			r = mid;
		}
	}
	printf("%d\n", l);
	return 0;
}
