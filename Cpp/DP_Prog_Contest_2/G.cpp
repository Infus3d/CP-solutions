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
 
const int N = 5e4+7;
const int M = 600;
const int MOD = 998244353;
const int K = 5e2+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int a, b, n, k, vis[N];
vector<int> E[N];
ll dp[N][K], ans[N], totAns;

void dfs(int x, int y){
	vis[x] = 1;
	dp[x][0] = 1;
	for(int i : E[x])
		if(i ^ x && !vis[i]){
			dfs(i, x);
			for(int j=0; j<k; j++){
				int cur = dp[i][j];
				int before = dp[x][k-j-1];
				ans[x] += cur * before;
			}
			
			for(int j=0; j<k; j++)
				dp[x][j+1] += dp[i][j];
		}
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i=1; i<n; i++){
		scanf("%d%d", &a, &b);
		E[a].pb(b);
		E[b].pb(a);
	}
	
	dfs(1, 0);
	
	for(int i=1; i<=n; i++)
		totAns += ans[i];
	
	printf("%lld\n", totAns);
	
	return 0;
}
