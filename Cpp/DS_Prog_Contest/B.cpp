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

struct segTree{
	int mn[N<<2], mx[N<<2];
	int n;
	
	segTree(const int arr[], int _n){
		n = _n;
		build_tree(arr, 1, n, 1);
	}
	
	void build_tree(const int arr[], int l, int r, int v){
		if(l == r){
			mn[v] = mx[v] = arr[l];
			return;
		}
		
		build_tree(arr, l, mid(l, r), v<<1);
		build_tree(arr, mid(l, r)+1, r, v<<1|1);
		
		mn[v] = min(mn[v<<1], mn[v<<1|1]);
		mx[v] = max(mx[v<<1], mx[v<<1|1]);
	}
	
	int getMin(int x, int y, int l, int r, int v){
		if(r < x || y < l)
			return MOD;
		
		if(x <= l && r <= y)
			return mn[v];
		
		return min(getMin(x, y, l, mid(l, r), v<<1), getMin(x, y, mid(l, r)+1, r, v<<1|1));
	}
	
	int getMax(int x, int y, int l, int r, int v){
		if(r < x || y < l)
			return -1;
		
		if(x <= l && r <= y)
			return mx[v];
		
		return max(getMax(x, y, l, mid(l, r), v<<1), getMax(x, y, mid(l, r)+1, r, v<<1|1));
	}
};

int testcase, n, k, d[N];

int main(){
	scanf("%d", &testcase);
	for(int caseNum=1; caseNum<=testcase; caseNum++){
		scanf("%d%d", &n, &k);
		for(int i=1; i<=n; i++) scanf("%d", d+i);
		
		segTree T(d, n);
		int ans = 0;
		for(int i=k; i<=n; i++)
			ans = max(ans, T.getMax(i-k+1, i, 1, n, 1) - T.getMin(i-k+1, i, 1, n, 1));
		
		printf("Case %d: %d\n", caseNum, ans);
	}
	return 0;
}
