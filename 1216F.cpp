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
const int INF = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += INF; a %= INF; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

ll T[N<<1];
int n, k;
char s[N];

ll get(int x, int l, int r, int v){
	if(l == r)
	   return T[v];
	
	if(x <= mid(l, r))
		return min(T[v], get(x, l, mid(l, r), v<<1));
	else
		return min(T[v], get(x, mid(l, r)+1, r, v<<1|1));
}

void upd(int x, int y, ll value, int l, int r, int v){
	if(y < l || r < x)
		return;
	
	if(x <= l && r <= y){
		umin(T[v], value);
		return;
	}
	
	upd(x, y, value, l, mid(l, r), v<<1);
	upd(x, y, value, mid(l, r)+1, r, v<<1|1);
}

void initiate(int l, int r, int v){
	T[v] = LLONG_MAX;
	
    if(l == r)
        return;
    
    initiate(l, mid(l, r), v<<1);
    initiate(mid(l, r)+1, r, v<<1|1);
}

int main(){
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	
	initiate(0, n, 1);
	upd(0, 0, 0, 0, n, 1);	
	
	for(int i=1; i<=n; i++){
		ll mini = LLONG_MAX;
		
		if(s[i-1] == '0'){
			mini = get(i-1, 0, n, 1);
			upd(i, i, mini+i, 0, n, 1);
		}
		else{
			mini = get(max(0, i-k-1), 0, n, 1);
			upd(max(1, i-k), min(n, i+k), mini+i, 0, n, 1);
		}
	}
	
	printf("%lld\n", get(n, 0, n, 1));
	
	return 0;
}

