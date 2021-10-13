#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"
 
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define db puts("*****")
#define mid(x , y) ((x+y)>>1)
#define ff first
#define ss second
#define all(x)	x.begin(),x.end()
#define ll long long
#define sqr(x)	((x)*(x))
#define pii pair <int , int>
#define pll pair <ll, ll>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day
 
using namespace std;
// using namespace __gnu_pbds;
 
const int N = 15;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int testcase, n, d[N+2][N+2];
long long dp[(1<<N)+2][3];

ll solve(){
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &d[i][j]);
	
	memset(dp, 0LL, sizeof(dp));
	dp[0][1] = 1LL;
	int m = (1<<n);
	for(int mask=0; mask<m; mask++)
		for(int i=0; i<n; i++)
			if(!(mask & (1<<i))){
				int dress = __builtin_popcount(mask), shoe = i;
				ll &next0 = dp[(mask^(1<<i))][0]; // only 0s and 1s
				ll &next1 = dp[(mask^(1<<i))][1]; // only 1s
				ll &next2 = dp[(mask^(1<<i))][2]; // 0s, 1s and 2s, but 2 is a must have
				
				if(d[dress][shoe] == 0){
					next2 += dp[mask][2];
					next0 += dp[mask][0] + dp[mask][1];
				}
				else if(d[dress][shoe] == 1){
					next0 += dp[mask][0];
					next1 += dp[mask][1];
					next2 += dp[mask][2];
				}
				else{
					next2 += dp[mask][0] + dp[mask][1] + dp[mask][2];
				}
			}
	
	return dp[m-1][1] + dp[m-1][2];
}

int main(){
	scanf("%d", &testcase);
	for(int i=1; i<=testcase; i++)
		printf("Case %d: %lld\n", i, solve());
	
	return 0;
}
/*
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

*/
