/*
Let L = [1, 2, 1, 0, 1, 0] correspond to the bracket sequence (())(), i.e. we do
+1 for '(' and -1 for ')'. The bracket is valid if L contains no negative values
and L[n] = 0. The naive solution will be O(n^3) but too slow. We need to make it
faster with dynamic programming.
Let dp[i][j][t] be 1 if it's possible to invert at most one segment in the range
[1, i] with exactly j opening brackets and t being the status of the inversion, and 0
otherwise. The status of the inverstion t is 0 if we have not inverted any segment
yet, 1 if we are in the process of inverting a segment meaning we are also inverting
the i'th bracket, and 2 if we have done exactly one inversion and bracket i is not inverted.

The transitions are then trivial, the below code should hopefully help you see it.
We have dp[2][N][3] instead of dp[N][N][3] to save some memory in the implementation. Since the
i'th position is only concerned with (i-1)'th position, there is no need to keep dp[1..i-2][N][3]
states.

Runtime O(n^2)
*/
#include "bits/stdc++.h"

using namespace std;

const int N = 5e3+2;

bool dp[2][N][3];
char s[N];

int n;

int main(){
	scanf("%s", s);
	n = strlen(s);
	
	dp[0][0][0] = 1;
	for(int i=1; i<=n; i++){
		int del = s[i-1] == '(' ? 1 : -1;
		int cur = i%2;
		for(int j=0; j<=n; j++){
			if(0 <= (j+del) && (j+del) <= n){
				dp[cur][j][1] |= dp[cur^1][j+del][1];
				dp[cur][j][1] |= dp[cur^1][j+del][0];
			}
			if(0 <= (j-del) && (j-del) <= n){
				dp[cur][j][0] |= dp[cur^1][j-del][0];
				dp[cur][j][2] |= dp[cur^1][j-del][1];
				dp[cur][j][2] |= dp[cur^1][j-del][2];
			}
		}
		
		for(int j=0; j<=n; j++){
			dp[cur^1][j][0] = dp[cur^1][j][1] = dp[cur^1][j][2] = 0;
		}
	}
	
	if(dp[n%2][0][0] || dp[n%2][0][1] || dp[n%2][0][2]){
		puts("possible");
	} else {
		puts("impossible");
	}
	
	return 0;
}
