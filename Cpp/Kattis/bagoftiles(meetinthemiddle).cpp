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

int g, n, m, t;
int d[2][N][K];
int arr[N];

int choose(){
	int a[N];
	int prod = 1;
	
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
	for(int z=1; z<=g; z++){
		scanf("%d", &m);
		for(int i=0; i<m; i++)
			scanf("%d", &arr[i]);
		scanf("%d%d", &n, &t);
		
		int fir = m/2+(m%2);
		int sec = m/2;
		
		memset(d, 0, sizeof(d));
		for(int i=0; i<(1<<fir); i++){
			int sum = 0;
			int cn = 0;
			for(int j=0; j<fir; j++)
				if(i&(1<<j))
					sum += arr[j], cn++;
			
			if(sum <= t)
				d[0][cn][sum]++;
		}
		
		for(int i=0; i<(1<<sec); i++){
			int sum = 0;
			int cn = 0;
			for(int j=0; j<sec; j++)
				if(i&(1<<j))
					sum += arr[j+fir], cn++;
			
			if(sum <= t)
				d[1][cn][sum]++;
		}
		
		int win = 0;
		for(int i=0; i<=n; i++)
			for(int j=0; j<=t; j++){
				win += d[0][i][j] * d[1][n-i][t-j];
				//~ printf("win: %d, d[0][i][j]: %d, d[1][n-i][t-j]: %d, i: %d, j: %d\n", win, d[0][i][j], d[1][n-i][t-j], i, j);
			}
		int total = choose();
		int lose = total - win;
		printf("Game %d -- %d : %d\n", z, win, lose);
	}
	return 0;
}
