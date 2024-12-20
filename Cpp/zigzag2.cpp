#include "bits/stdc++.h"

using namespace std;

int main(){
	int n; scanf("%d", &n);
	vector<int> a(n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	auto calc = [&](bool inc){
		int ret = 1;
		for(int i=1; i<n; i++){
			if(inc && a[i] < a[i-1]){
				ret++;
				inc = !inc;
			}
			if(!inc && a[i] > a[i-1]){
				ret++;
				inc = !inc;
			}
		}
		return ret;
	};
	int ans1 = calc(0);
	int ans2 = calc(1);
	printf("%d\n", max(ans1, ans2));
	return 0;
}
