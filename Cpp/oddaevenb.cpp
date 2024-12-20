#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9+7;

int main(){
	int n; scanf("%d", &n);
	vector<vector<int>> dp(n+1, vector<int>(2, 0));
	dp[0][0] = dp[0][1] = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j+=2){
			dp[i][0] = (dp[i][0] + dp[i-j][1]) % MOD;
		}
		for(int j=2; j<=i; j+=2){
			dp[i][1] = (dp[i][1] + dp[i-j][0]) % MOD;
		}
	}
	printf("%d\n", (dp[n][0] + dp[n][1]) % MOD);
	return 0;
}
