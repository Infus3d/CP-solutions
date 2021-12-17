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
const int MOD = 1e9+7;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int testcase, k, a, b;
int dp[N];

int main(){
    scanf("%d%d", &testcase, &k);
    
    dp[0] = 1;
    for(int i=0; i<=1e5; i++){
        dp[i+1] = (dp[i+1] + dp[i]) % MOD;
        if(i+k <= 1e5)
            dp[i+k] = (dp[i+k] + dp[i]) % MOD;
    }
    
    dp[0] = 0;
    for(int i=1; i<=1e5; i++)
        dp[i] = (dp[i-1] + dp[i]) % MOD;
    
    while(testcase--){
        scanf("%d%d", &a, &b);
        printf("%d\n", (dp[b] - dp[a-1] + MOD) % MOD);
    }
    
	return 0;
}
