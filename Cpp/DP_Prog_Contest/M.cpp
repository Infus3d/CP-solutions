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
 
const int N = 1e2+7;
const int M = 600;
const int MOD = 998244353;
const int K = 5e2+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, k, d[K];
int fun[N], cost[N];

int main(){
	while(true){
		scanf("%d%d", &k, &n);
		if(n == k && !n)
			break;
		
		for(int i=1; i<=n; i++)
			scanf("%d%d", &cost[i], &fun[i]);
		
		memset(d, -1, sizeof(d));
		d[0] = 0;
		for(int i=1; i<=n; i++)
			for(int j=k; j>=0; j--)
				if(~d[j] && j+cost[i] <= k)
					umax(d[j+cost[i]], d[j] + fun[i]);
		
		int mfun = -1, mcost = 0;
		for(int i=0; i<=k; i++)
			if(d[i] > mfun)
				mfun = d[i], mcost = i;
		printf("%d %d\n", mcost, mfun);
	}
	return 0;
}
