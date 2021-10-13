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

int a, b, n, d[N];
vector<int> E[N];
bool distinct = true, vis[N];

struct mytree{
	int mx[N], mn[N], root;
	bool vis[N];
	
	void dfs(int x, int y = 0){
		mx[x] = mn[x] = d[x];
		vis[x] = true;
		
		for(int i : E[x])
			if(i ^ y && !vis[i]){
				dfs(i, x);
				umin(mn[x], mn[i]);
				umax(mx[x], mx[i]);
			}	
	}
	
	void dfs(){
		dfs(root);
	}
	
	bool check(){
		for(int i : E[root])
			if(mn[i] ^ mx[i])
				return false;
		
		return true;
	}
} r1, r2;

void dfs(int x, int y){
	vis[x] = true;
	for(int i : E[x])
		if(i ^ x && !vis[i]){
			if(distinct && d[i] != d[x]){
				distinct = false;
				r1.root = x, r2.root = i;
			}
			dfs(i, x);
		}
}

int main(){
	scanf("%d", &n);
	for(int i=1; i<n; i++){
		scanf("%d%d", &a, &b);
		E[a].pb(b);
		E[b].pb(a);
	}
	for(int i=1; i<=n; i++)
		scanf("%d", d+i);
	
	dfs(1, 0);
	r1.dfs();
	r2.dfs();
	
	if(distinct)
		puts("YES\n1");
	else if(r1.check())
		printf("YES\n%d\n", r1.root);
	else if(r2.check())
		printf("YES\n%d\n", r2.root);
	else
		puts("NO");
	
	return 0;
}
