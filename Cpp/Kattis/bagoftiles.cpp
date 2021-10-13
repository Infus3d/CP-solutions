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
 
const int N = 32;
const int M = 600;
const int MOD = 998244353;
const int K = 1e4+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int g, m, n, t;
int d[N], dp[N][N][K];
int cn;

long long choose(){
	int a[N];
	long long prod = 1;
	
	for(int i=1; i<=m; i++)	a[i] = i;
	for(int i=1; i<=min(n, m-n); i++){
		int v = i;
		for(int j=max(n, m-n)+1; j<=m; j++){
			if(v == 1) break;
			
			int gcd = __gcd(v, a[j]);
			a[j] /= gcd;
			v /= gcd;
		}
		
		prod *= v;
	}
	
	for(int i=max(n, m-n)+1; i<=m; i++)
		prod *= a[i];
	
	return prod;
}

int main(){
	scanf("%d", &g);
	while(g--){
		cn++;
		scanf("%d", &m);
		for(int i=1; i<=m; i++)
			scanf("%d", &d[i]);
		scanf("%d%d", &n, &t);
		
		for(int i=0; i<=m; i++)
			for(int j=0; j<=n; j++)
				for(int k=0; k<=t; k++)
					dp[i][j][k] = 0;
		
		dp[0][0][0] = 1;
		for(int i=1; i<=m; i++){
			for(int j=0; j<=n; j++)
				for(int k=0; k<=t; k++){
					if(j > 0 && k >= d[i])
						dp[i][j][k] += dp[i-1][j-1][k-d[i]];
					dp[i][j][k] += dp[i-1][j][k];
				}
		}
		
		long long total = choose();
		long long win = dp[m][n][t];
		long long loss = total - win;
		printf("Game %d -- %lld : %lld\n", cn, win, loss);
	}
	
	
	return 0;
}
