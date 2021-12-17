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
 
const int N = 2e5+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
const long long INF = 1e18;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

struct segTree{
	ll T[N<<2], lz[N<<2];
	
	segTree(){
		memset(T, 0, sizeof(T));
		memset(lz, 0, sizeof(lz));
	}
	
	void push(int v){
		if(!lz[v])	return;
		T[v<<1] += lz[v];
		T[v<<1|1] += lz[v];
		
		lz[v<<1] += lz[v];
		lz[v<<1|1] += lz[v];
		
		lz[v] = 0LL;
	}
	
	void upd(int x, int y, int val, int l, int r, int v){
		if(r < x || y < l)	return;
		if(x <= l && r <= y){
			T[v] += val;
			lz[v] += val;
			return;
		}
		
		push(v);
		
		upd(x, y, val, l, mid(l, r), v<<1);
		upd(x, y, val, mid(l, r)+1, r, v<<1|1);
		
		T[v] = min(T[v<<1], T[v<<1|1]);
	}
	
	ll getMin(int x, int y, int l, int r, int v){
		if(r < x || y < l)
			return INF;
		
		if(x <= l && r <= y)
			return T[v];
		
		push(v);
		
		return min(getMin(x, y, l, mid(l, r), v<<1), getMin(x, y, mid(l, r)+1, r, v<<1|1));
	}
} T; 

int n, q, d[N], a[3];
string str;

int getInt(const string &str, int l, int r){
	int cur = 0;
	for(int i=l; i<=r; i++)
		cur = (cur * 10) + (str[i] - '0');
	
	return cur;
}

int parse(const string &str, int arr[]){
	if(!sz(str)) return 0;
	int cn = 0, mul = 1, len = 0;
	
	for(int i=0; i<sz(str); i++){
		if(str[i] == ' '){
			arr[cn++] = mul * getInt(str, i-len, i-1);
			len = 0, mul = 1;
		}
		else if(str[i] == '-')
			mul = -1;
		else
			len++;
	}
	
	return cn;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i=1; i<=n; i++){	
		cin >> d[i];
		T.upd(i, i, d[i], 1, n, 1);
	}
	
	cin >> q;
	getline(cin, str);
	while(q--){
		getline(cin, str); str += " ";
		//~ cout << "*** " << str << "\n";
		int count = parse(str, a);
		a[0]++, a[1]++;
		
		//~ cout << count << " " << a[0] << " " << a[1] << " " << a[2] << "\n";
		if(count == 2){
			if(a[0] <= a[1])
				cout << T.getMin(a[0], a[1], 1, n, 1) << "\n";
			else
				cout << min(T.getMin(a[0], n, 1, n, 1), T.getMin(1, a[1], 1, n, 1)) << "\n";
		}
		else{
			if(a[0] <= a[1])
				T.upd(a[0], a[1], a[2], 1, n, 1);
			else{
				T.upd(a[0], n, a[2], 1, n, 1);
				T.upd(1, a[1], a[2], 1, n, 1);
			}
		}
	}
	
	return 0;
}
