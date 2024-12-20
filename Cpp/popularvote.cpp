#include "bits/stdc++.h"

using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		vector<pair<int, int>> a;
		int total = 0;
		for(int i=0; i<n; i++){
			int x; scanf("%d", &x);
			a.push_back({x, i});
			total += x;
		}
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		assert((int)a.size() > 1);
		if(a[0].first == a[1].first){
			puts("no winner");
		} else {
			if(a[0].first > (total / 2)){
				printf("majority winner %d\n", a[0].second+1);
			} else {
				printf("minority winner %d\n", a[0].second+1);
			}
		}
	}
	return 0;
}
