#include "iostream"
#include "string.h"
 
using namespace std;
 
const int N = 1007;

int n, k, q, d[N];
int dp[2][2][N];

int main(){
	int a[4]; a[0] = 1, a[1] = 2, a[2] = 3, a[3] = 4;
	printf("%d\n", *a);
	printf("%d", a[0]);
	
	scanf("%d", &q);
	for(int t=1; t<=q; t++){
		scanf("%d%d", &n, &k);
		for(int i=1; i<=n; i++)
			scanf("%d", &d[i]);
		
		for(int i=0; i<=k; i++)
			for(int j=0; j<2; j++)
				for(int g=0; g<2; g++)
					dp[j][g][i] = 0;
		
		dp[0][0][0] = 1;
		for(int i=1; i<=n; i++){
			for(int j=0; j<=k; j++)
				dp[1][0][j] = (dp[0][0][j] | dp[0][1][j]);
			
			for(int j=0; j<=k; j++)
				if(dp[0][0][j] && j+d[i] <= k)
					dp[1][1][j+d[i]] = 1;
			
			for(int j=0; j<=k; j++)
				for(int v=0; v<2; v++){
					dp[0][v][j] = dp[1][v][j];
					dp[1][v][j] = 0;
				}
		}
		
		int ans = 0;
		for(int i=k; i>=0; i--)
			if((dp[0][0][i] | dp[0][1][i])){
				ans = i;
				break;
			}
		
		printf("Scenario #%d: %d\n", t, ans);
	}
	return 0;
}
