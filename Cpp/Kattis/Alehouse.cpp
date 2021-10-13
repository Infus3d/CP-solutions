#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

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
using namespace __gnu_pbds;
 
const int N = 1e5+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, k, ans, cn, f[N];
pii d[N];
ordered_set setik;

int main(){
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		d[i] = mp(a, b);
	}
	sort(d+1, d+n+1);
	
	for(int i=1; i<=n; i++){
		int number = d[i].ff - k;
		int cur = sz(setik) - setik.order_of_key(mp(number, -1)) + 1;
		ans = max(ans, cur);
		setik.insert(mp(d[i].ss, cn++));
	}
	
	printf("%d\n", ans);

	return 0;
}
