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
 
const int N = 1e4+7;
const int M = 600;
const int MOD = 10000007;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int q, d[N], a[6], n;

int f(int x){
	if(x < 6)
		return a[x];
	if(~d[x])
		return d[x];
	
	int tr = 0;
	for(int i=6; i>=1; i--)
		tr = (tr + f(x-i)) % MOD;
	
	return d[x] = tr;
}

int main(){
	scanf("%d", &q);
	for(int t=1; t<=q; t++){
		memset(d, -1, sizeof(d));
		for(int j=0; j<6; j++)
			scanf("%d", a+j);
		
		scanf("%d", &n);
		printf("Case %d: %d\n", t, f(n) % MOD);
	}
	
	return 0;
}
