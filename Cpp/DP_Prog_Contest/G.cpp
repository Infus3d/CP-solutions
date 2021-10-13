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
 
const int N = 2e3+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

vector<int> primes;
int n, k;
int d[N], dp[N][16];

int main(){
	for(int i=2; i<=1120; i++)
		if(!d[i])
			for(int j=i+i; j<=1120; j+=i)
				d[j] = 1;
	
	for(int i=2; i<=1120; i++)
		if(!d[i])
			primes.pb(i);
	
	printf("%d\n", sz(primes));
	
	dp[0][0] = 1;
	for(int v : primes){
		for(int i=1120; i>=0; i--)
			for(int j=0; j<=13; j++)
				if(dp[i][j] && i+v <= 1120)
					dp[i+v][j+1] += dp[i][j];
	}
	
	while(true){
		scanf("%d%d", &n, &k);
		if(n == k && !n) break;
		printf("%d\n", dp[n][k]);
	}
	return 0;
}
