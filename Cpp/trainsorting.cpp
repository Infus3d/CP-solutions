/*
Only the first chosen train matters. Afterwards, the left of the train will just be longest
decreasing subsequence and the right of the train becomes the longest increasing subsequence
in the optimal solution. So, just calculate the LIS and LDS ending at each index i. The answer is
LIS[i] + LDS[i] over all i.

Runtime O(n^2)
*/
#include "bits/stdc++.h"

using namespace std;

int main(){
	int n; scanf("%d", &n);
	vector<int> a(n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	vector<int> lis(n, 1), lds(n, 1);
	int ans = 1;
	for(int i=n-1; i>=0; i--){
		for(int j=i+1; j<n; j++){
			if(a[j] < a[i]){
				lis[i] = max(lis[i], lis[j] + 1);
			}
			if(a[j] > a[i]){
				lds[i] = max(lds[i], lds[j] + 1);
			}
		}
		ans = max(ans, lis[i] + lds[i]);
	}
	printf("%d\n", ans-1);
	return 0;
}
