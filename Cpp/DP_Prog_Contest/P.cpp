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

int q, A[N], B[N];
int n, m, d[N][N];
int ans;

int lcs(int x, int y){
	//~ printf("enter --> x:%d, y:%d\n", x, y);
	//~ printf("A:\n");
	//~ for(int i=1; i<=x; i++)
		//~ printf("%d ", A[i]);
	//~ printf("\nB:\n");
	//~ for(int i=1; i<=y; i++)
		//~ printf("%d ", B[i]);
	//~ printf("\n");
	
	memset(d, 0, sizeof(d));
	for(int i=1; i<=x; i++)
		for(int j=1; j<=y; j++){
			umax(d[i][j], max(d[i-1][j], d[i][j-1]));
			umax(d[i][j], d[i-1][j-1] + (A[i] == B[j] ? 1 : 0));
		}
	
	return d[x][y];
}

int main(){
	scanf("%d", &q);
	while(q--){
		n = 1; ans = 0;
		while(true){
			scanf("%d", &A[n++]);
			if(A[n-1] == 0)
				break;
		}
		n--;
		
		while(true){
			m = 1;
			scanf("%d", &B[m++]);
			if(B[m-1] == 0)
				break;
			
			while(true){
				scanf("%d", &B[m++]);
				if(B[m-1] == 0)
					break;
			}
			
			// ans = max(ans, newAns);
			
			m--;
			ans = max(ans, lcs(n, m));
		}
		
		printf("%d\n", ans-1);
	}
	
	return 0;
}
