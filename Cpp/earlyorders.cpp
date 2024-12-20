#include "bits/stdc++.h"

using namespace std;

const int N = 2e5+1;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(n+1);
	vector<int> u(n+1);
	vector<int> lastIdx(k+1, 0);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=n; i>=1; i--){
		if(!lastIdx[a[i]]){
			lastIdx[a[i]] = i;
			u[i] = (i == n) ? 1 : u[i+1]+1;
		} else {
			u[i] = u[i+1];
		}
	}
	int l = 0;
	int r = 0;
	vector<bool> available(k+1, true);
	vector<int> partial(n+2, 0);
	vector<int> ans;
	set<pair<int, int>> setik;
	for(int i=0; i<k; i++){
		while(r < n && (u[r+1] - i + partial[r+1]) == (k - i)){
			r++;
			partial[r+1] += partial[r]; // carry out the partial sum as you go
			if(available[a[r]]){
				setik.insert({a[r], r});
			}
		}
		auto [val, idx] = *setik.begin();
		while(!available[val]){
			setik.erase(setik.begin());
			assert(!setik.empty());
			val = (*setik.begin()).first;
			idx = (*setik.begin()).second;
		}
		while(l < idx){
			l++;
			if(setik.find({a[l], l}) != setik.end()){
				setik.erase({a[l], l});
			}
		}
		ans.push_back(val);
		available[val] = false;
		partial[lastIdx[val]+1]++;  // adding -1 to [i, lastIdx[va]] is the same as {adding -1 to current and +1 to (lastIdx[val]+1) and carrying out the partial sum}
	}
	assert((int)ans.size() == k);
	for(int i : ans){
		printf("%d ", i);
	}
	puts("");
	
	return 0;
}
