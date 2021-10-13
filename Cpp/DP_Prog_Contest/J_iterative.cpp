#include "iostream"
#include "stdio.h"
#include "string.h"

using namespace std;
 
const int K = 105;
const int N = 67;

int testcase;
int n, k;
long long dp[N][N][K];

int main(){
	scanf("%d", &testcase);
	for(int t=1; t<=testcase; t++){
		scanf("%d%d", &n, &k);
		memset(dp, 0, sizeof(dp));
		
		if(k > 1)	dp[0][1][1] = 1LL;
		else 		dp[0][1][0] = 1LL;
		
		for(int i=0; i<n; i++)
			for(int j=0; j<=n; j++)
				for(int h=0; h<k; h++){
					dp[i+1][j+1][((h*2)+1)%k] += dp[i][j][h];
					dp[i+1][j][(h*2)%k] += dp[i][j][h];
				}
				
		printf("Case %d: %lld\n", t, ((n%2 || !k) ? 0LL : dp[n-1][n/2][0]));
	}
	
	return 0;
}
