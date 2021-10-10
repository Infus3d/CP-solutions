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

const int N = 1e5+7;
const int INF = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += INF; a %= INF; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int t, n, m;
char s[62];
ll dp[62][62];

ll fun(int l, int r){
	if(r < l)	
		return 0LL;
	
	if(~dp[l][r])	
		return dp[l][r];
	
	if(l == r)	
		return dp[l][r] = 1;
	
	dp[l][r] = fun(l+1, r-1) * (s[l] == s[r]) + (s[l] == s[r]);
	dp[l][r] += fun(l, r-1) + fun(l+1, r) - fun(l+1, r-1);
	
	return dp[l][r];
}

int main(){
	scanf("%d", &t);
	
	while(t--){
		scanf("%s", s);
		n = strlen(s);
		
		memset(dp, -1, sizeof(dp));
		
		printf("%lld\n", fun(0, n-1));
	}
	
	return 0;
}

