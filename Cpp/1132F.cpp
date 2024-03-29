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
 
const int N = 5e2+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n;
char s[N];
int dp[N][N];

int rec(int l, int r){
	//~ printf("enter l:%d, r:%d\n", l, r);
	if(l > r)	return 0;
	if(l == r) return 1;
	int &ret = dp[l][r];
	if(~ret) return ret;
	ret = rec(l+1, r) + 1;
	
	for(int i=l+1; i<=r; i++)
		if(s[i] == s[l])
			umin(ret, rec(l+1, i-1) + rec(i, r));
	
	return ret;
}

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	
	memset(dp, -1, sizeof dp);
	printf("%d\n", rec(0, n-1));
	
	return 0;
}
