/*
Let E(S) be the expected number of turns in a game if only the children in S are still playing. As a base case, if there are two or fewer children in S, then E(S) = 0.

For each child in S, we can compute the probability that the child sits out in O(n) time by summing the probability of the two cases they sit out: they put in black, all others put in white and vice-versa. Let the probability that the child sits out be sit_i. Then we have the following recurrence:

E(S) = 1 + sit_1 E(S \ {1}) + sit_2 E(S \ {2}) + ... + (1 - \sum sit_i) E(S).

Each sit_i can be computed in O(N), and there are 2^n values of S for an overall time complexity of O(N^2 * 2^N). This can be improved to O(N * 2^N) by computing sit_i from the value of sit_{i - 1}, but this optimization is not needed.
*/
#include "bits/stdc++.h"

using namespace std;

int main(){
	int n; scanf("%d", &n);
	vector<double> a(n);
	for(int i=0; i<n; i++){
		scanf("%lf", &a[i]);
	}
	vector<double> dp((1<<n), 0.0);
	for(int mask=0; mask<(1<<n); mask++){
		if(__builtin_popcount(mask) <= 2) continue; // base case is |S| = 2 children, where E(S) = 0
		double allwhite = 1.0, allblack = 1.0;
		for(int i=0; i<n; i++){
			if((1<<i)&mask){
				allwhite *= a[i];
				allblack *= (1 - a[i]);
			}
		}
		dp[mask] = 1.0;
		double total_out = 0.0;
		for(int i=0; i<n; i++){
			if((1<<i)&mask){
				double out_white = allblack / (1 - a[i]) * a[i];
				double out_black = allwhite / a[i] * (1 - a[i]);
				total_out += (out_white + out_black);
				dp[mask] += (out_white + out_black) * dp[mask ^ (1<<i)];
			}
		}
		dp[mask] /= total_out;
	}
	printf("%.6lf\n", dp[(1<<n)-1]);
	return 0;
}
