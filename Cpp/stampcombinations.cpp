/*
Because n*m <= 10^7, we can do linear number of operations per query.
Let pref[i] be the prefix sum of [1...i] and suf[i] be the suffix sum
of [i..n]. Then you just need to find if there are two indices i < j,
where pref[i] + suf[j] = q. Don't forget the edge cases where pref[0] = 0
or suf[n+1] = 0!

Runtime O(n*m)
*/
#include "bits/stdc++.h"

using namespace std;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> a(n), b(n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	map<int, bool> cnt;
	cnt[0] = true;
	for(int i=n-1; i>=0; i--){
		if(i < n-1){
			b[i] += b[i+1];
		}
		cnt[b[i]] = true;
	}
	while(m--){
		int q;
		scanf("%d", &q);
		int sofar = 0;
		int idx = n-1;
		bool found = cnt[q];
		for(int i=0; i<n; i++){
			cnt[b[i]] = false;
			sofar += a[i];
			if(cnt[q-sofar] > 0){
				found = true;
				idx = i;
				break;
			}
		}
		for(int i=idx; i>=0; i--){
			cnt[b[i]] = true;
		}
		printf("%s\n", found ? "Yes" : "No");
	}
	
	return 0;
}
