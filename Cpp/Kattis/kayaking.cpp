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
 
const int N = 1e5+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int a[4], b[4], c[4];
int d[N], f[N];
int n, cn;
pair<int, pii> p[7];

bool doesRemain(int u){
	if(p[u].ss.ff != p[u].ss.ss)
		return c[p[u].ss.ff] && c[p[u].ss.ss];
	else
		return c[p[u].ss.ff] >= 2;
}

bool can(ll x){
	for(int i=1; i<=3; i++) 
		c[i] = a[i];
	
	for(int i=n; i>=1; i--){
		int needed = x;	
		for(int j=1; j<=6; j++)
			if(doesRemain(j) && p[j].ff * d[i] >= needed){
				needed -= p[j].ff * d[i];
				c[p[j].ss.ff]--;
				c[p[j].ss.ss]--;
				break;
			}
		
		if(needed > 0)
			return false;
	}
	
	return true;
}

int main(){
	scanf("%d%d%d", &a[1], &a[2], &a[3]);
	scanf("%d%d%d", &b[1], &b[2], &b[3]);
	
	for(int i=1; i<=3; i++)
		for(int j=i; j<=3; j++)
			p[++cn] = mp(b[i] + b[j], mp(i, j));
	sort(p+1, p+7);
	
	n = (a[1] + a[2] + a[3]) / 2;
	for(int i=1; i<=n; i++)
		scanf("%d", d+i);
	sort(d+1, d+n+1);
	
	ll l=1, r=200000000;
	while(l+1 < r){
		int m = mid(l, r);
		if(can(m))
			l = m;
		else
			r = m-1;
	}
	if(can(r)) l = r;
	
	printf("%lld\n", l);
	
	return 0;
}
