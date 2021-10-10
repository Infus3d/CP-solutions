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

const int N = 1e3+7;
const int INF = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += INF; a %= INF; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int dp[N*5][N+8], testCase, arr[N*5];
int K, n;

int main(){
	scanf("%d", &testCase);
	
	while(testCase--){
		memset(dp, 0, sizeof(dp));
		
		scanf("%d%d", &K, &n); K += 8;
		
		for(int i=1; i<=n; i++)	scanf("%d", &arr[i]);
		
		for(int i=1; i<=n+2; i++)
			for(int j=0; j<K+2; j++)
				dp[i][j] = INT_MAX;
		
		dp[n+1][0] = 0;
		
		for(int i=n; i>=1; i--){
			for(int j=0; j<=(n-i+1)/3; j++)
				umin(dp[i][j], dp[i+1][j]);
				
			for(int j=(n-i+1)/3; j>=1; j--)
				umin(dp[i][j], min(dp[i+3][j-1] + sqr(arr[i+1] - arr[i]), dp[i+2][j-1] + sqr(arr[i+1] - arr[i])));
		}
		
		printf("%d\n", dp[1][K]);
	}
	
	return 0;
}

