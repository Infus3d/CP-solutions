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

int testcase, n, ans, d[N];
pii bridge[N];

int main(){
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
			scanf("%d", &bridge[i].ff);
		for(int i=1; i<=n; i++)
			scanf("%d", &bridge[i].ss), bridge[i].ss += 1000;
		
		ans = 0;
		sort(bridge+1, bridge+n+1);
		memset(d, 0, sizeof(d));
		for(int i=1; i<=n; i++){
			int curmax = 0;
			for(int j=0; j<=bridge[i].ss; j++)
				umax(curmax, d[j]);
			umax(d[bridge[i].ss], curmax + 1);
			umax(ans, d[bridge[i].ss]);
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}
