#include "bits/stdc++.h"

using namespace std;

int main(){
	int n; scanf("%d", &n);
	vector<long long> a(n);
	for(int i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	int half = n/2;
	int other = n - half;
	vector<long long> x;
	for(int mask=0; mask<(1<<half); mask++){
		long long sum = 0;
		for(int i=0; i<half; i++){
			if((mask >> i)&1){
				sum += a[i];
			}
		}
		x.push_back(sum);
	}
	sort(x.begin(), x.end());
	vector<long long> y;
	for(int mask=0; mask<(1<<other); mask++){
		long long sum = 0;
		for(int i=0; i<other; i++){
			if((mask >> i)&1){
				sum += a[i+half];
			}
		}
		y.push_back(sum);
	}
	sort(y.begin(), y.end());
	auto getCount = [&](long long lim){
		int j = (int)y.size() - 1;
		long long ret = 0;
		for(int i=0; i<(int)x.size(); i++){
			while(j >= 0 && (x[i] + y[j]) >= lim){
				j--;
			}
			ret += j+1;
		}
		return ret;
	};
	long long l = 1, r = (1LL<<n)-1;
	while(l+1 < r){
		long long mid = (l + r) / 2LL;
		long long rsum = getCount(r) - getCount(mid);
		long long lsum = getCount(mid) - getCount(l);
		if(rsum > lsum){
			l = mid;
		} else {
			r = mid;
		}
	}
	printf("%lld\n", l);
	return 0;
}
