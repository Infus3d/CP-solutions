#include "iostream"
#include "stdio.h"

using namespace std;
 
const int N = 66;
const int K = 102;

int testcase;
int n, k;
long long dp[N][N][K];

long long rec(int x, int ones, int mod){
	if(x == n && mod == 0 && ones*2 == n)
		return 1LL;
	if(x >= n || ones*2 > n)
		return 0LL;
	
	long long ret = dp[x][ones][mod];
	if(~ret) return ret;
	
	ret = rec(x+1, ones+1, ((mod*2)+1)%k) + rec(x+1, ones, (mod*2)%k);
	return dp[x][ones][mod] = ret;
}

int main(){
	scanf("%d", &testcase);
	for(int t=1; t<=testcase; t++){
		scanf("%d%d", &n, &k);
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				for(int p=0; p<K; p++)
					dp[i][j][p] = -1LL;
		
		printf("Case %d: %lld\n", t, rec(1, 1, 1));
	}
	
	return 0;
}
