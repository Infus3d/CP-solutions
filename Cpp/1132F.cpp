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
	
	ret = MOD;
	int sum[27], cur[27];
	memset(sum, 0, sizeof sum);
	for(int i=0; i<26; i++) cur[i] = l-1;
	for(int i=l; i<=r; i++){
		int ind = s[i] - 'a';
		sum[ind] += rec(cur[ind]+1, i-1);
		cur[ind] = i;
	}
	for(int i=0; i<26; i++)
		sum[i] += rec(cur[i]+1, r);
	
	for(int i=0; i<26; i++){
		if(cur[i] != l-1){
			ret = min(ret, sum[i]);
			//~ printf("l:%d, r:%d, i:%d, ret:%d, sum[i]:%d\n", l, r, i, ret, sum[i]);
		}
	}
	
	//~ printf("exit l:%d, r:%d, ret:%d\n", l, r, ret+1);
	return ++ret;
}

int main(){
	printf("%f\n", float(1/2));
	scanf("%d", &n);
	scanf("%s", s);
	
	memset(dp, -1, sizeof dp);
	printf("%d\n", rec(0, n-1));
	
	return 0;
}
