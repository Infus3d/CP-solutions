#include "bits/stdc++.h"

using namespace std;

const int N = 2e5+1;
const int INF = 1e6+1;

int T[N<<2];

void upd(int x, int val, int l, int r, int v){
	if(l == r){
		T[v] = val;
		return;
	}
	int mid = (l + r) / 2;
	if(x <= mid){
		upd(x, val, l, mid, v<<1);
	} else {
		upd(x, val, mid+1, r, v<<1|1);
	}
	T[v] = min(T[v<<1], T[v<<1|1]);
}

int getMin(int x, int y, int l, int r, int v){
	if(y < l || r < x){
		return INF;
	}
	if(x <= l && r <= y){
		return T[v];
	}
	int mid = (l + r) / 2;
	return min(getMin(x, y, l, mid, v<<1), getMin(x, y, mid+1, r, v<<1|1));
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(n+1);
	vector<int> u(n+1);
	vector<int> lastIdx(k+1, 0);
	vector<vector<int>> indices(k+1, vector<int>());
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		indices[a[i]].push_back(i);
		upd(i, a[i], 1, n, 1);
	}
	for(int i=n; i>=1; i--){
		if(!lastIdx[a[i]]){
			lastIdx[a[i]] = i;
			u[i] = (i == n) ? 1 : u[i+1]+1;
		} else {
			u[i] = u[i+1];
		}
	}
	int l = 0, r = 0;
	vector<int> partial(n+2);
	vector<int> ans;
	for(int i=0; i<k; i++){
		while(r < n && (u[r+1] - i + partial[r+1]) == (k-i)){
			r++;
			partial[r+1] += partial[r];
		}
		int val = getMin(l+1, r, 1, n, 1);
		assert(val <= k);
		
		ans.push_back(val);
		for(int j : indices[val]){
			upd(j, INF, 1, n, 1);
		}
		partial[lastIdx[val]+1]++;
		l = *lower_bound(indices[val].begin(), indices[val].end(), l);
	}
	for(int i : ans){
		printf("%d ", i);
	}
	puts("");
	return 0;
}

// 1 2 3 4 5 6 7 8 9 10
// --------------------
// 5 4 3 2 1 4 1 1 5 5
// 5 5 5 4 3 3 2 2 1 1
