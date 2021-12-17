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
	ll T[N<<2];
	
	segTree(){
		memset(T, 0, sizeof(T));
	}
	
	void upd(int x, int val, int flag, int l, int r, int v){
		if(l == r){
			if(flag)
				T[v] = val;
			else
				T[v] += val;
			return;
		}
		
		if(x <= mid(l, r))
			upd(x, val, flag, l, mid(l, r), v<<1);
		else
			upd(x, val, flag, mid(l, r)+1, r, v<<1|1);
		
		T[v] = T[v<<1] + T[v<<1|1];
	}
	
	ll get(int x, int y, int l, int r, int v){
		if(r < x || y < l)
			return 0LL;
		
		if(x <= l && r <= y)
			return T[v];
		
		return get(x, y, l, mid(l, r), v<<1) + get(x, y, mid(l, r)+1, r, v<<1|1);
	}
};

int testcase, n, q, type, a, b;

int main(){
	scanf("%d", &testcase);
	for(int caseNum=1; caseNum<=testcase; caseNum++){
		scanf("%d%d", &n, &q);
		
		segTree T;
		for(int i=1; i<=n; i++){
			scanf("%d", &a);
			T.upd(i, a, 0, 1, n, 1);
		}
		
		printf("Case %d:\n", caseNum);
		while(q--){
			scanf("%d", &type);
			if(type == 1){
				scanf("%d", &a); a++;
				printf("%lld\n", T.get(a, a, 1, n, 1));
				T.upd(a, 0, 1, 1, n, 1);
			}
			else if(type == 2){
				scanf("%d%d", &a, &b); a++;
				T.upd(a, b, 0, 1, n, 1);
			}
			else{
				scanf("%d%d", &a, &b); a++; b++;
				printf("%lld\n", T.get(a, b, 1, n, 1));
			}
		}
	}
	
	return 0;
}
