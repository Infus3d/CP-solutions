/*
ID : omarmuh1
PROG : test
LANG : C++11
*/

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
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day

using namespace std;
using namespace __gnu_pbds;

const int N = 2e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, q, p[N], pprev[N], pnext[N], arr[N], d[N], nextt[N][20], vis[N];
set<pii> setik[N];
char ans[N];
vector<pii> E[N];
bool T[N<<2];

void upd(int x, int l, int r, int v){
	if(l == r){
		T[v] = true;
		return;
	}
	if(x <= mid(l, r))
		upd(x, l, mid(l, r), v<<1);
	else
		upd(x, mid(l, r)+1, r, v<<1|1);
	T[v] = T[v<<1]|T[v<<1|1];
}

bool get(int x, int y, int l, int r, int v){
	if(y < l || r < x)
		return 0;
	if(x <= l && r <= y)
		return T[v];
	return get(x, y, l, mid(l, r), v<<1) | get(x, y, mid(l, r)+1, r, v<<1|1);
}

int getLeftmost(int x){
	int k = n-1;
	for(int i=19; i>=0; i--)
		if(k - (1<<i) >= 0)
			x = nextt[x][i], k -= (1<<i);
	return x;
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i=1; i<=n; i++)	scanf("%d", &p[i]);
	for(int i=1; i<=m; i++)	scanf("%d", &arr[i]);
	for(int i=1; i<=n; i++){	
		pnext[p[i == 1 ? n : i-1]] = p[i];
		pprev[p[i]] = p[i == 1 ? n : i-1];
	}
	for(int i=m; i>=1; i--){
		vis[arr[i]] = i;
		nextt[i][0] = vis[pnext[arr[i]]];
	}
	
	for(int j=1; j<20; j++)
		for(int i=1; i<=m; i++)
			if(nextt[i][j-1] > 0)
				nextt[i][j] = nextt[nextt[i][j-1]][j-1];
			
	for(int i=0; i<q; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].pb({b, i});
	}
	
	for(int i=m; i>=1; i--){
		d[i] = d[nextt[i][0]]+1;
		int tr = getLeftmost(i);
		if(d[i]-n >= 0)	upd(tr, 1, m, 1);
		
		for(pii j : E[i])
			ans[j.ss] = get(i, j.ff, 1, m, 1) + '0';
	}
	puts(ans);
	
	return 0;
}