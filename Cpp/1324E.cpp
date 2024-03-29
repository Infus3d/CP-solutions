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
 
const int N = 2e3+2;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, h, l, r;
int dp[N][N], d[N];

int main(){
    scanf("%d%d%d%d", &n, &h, &l, &r);
    for(int i=1; i<=n; i++)
        scanf("%d", &d[i]);
    
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i=1; i<=n; i++)
        for(int j=0; j<h; j++){
            if(dp[i-1][j] != -1){
                int one = (j+d[i])%h;
                int two = (j+d[i]-1)%h;
                umax(dp[i][one], dp[i-1][j] + ((one >= l && one <= r) ? 1 : 0));
                umax(dp[i][two], dp[i-1][j] + ((two >= l && two <= r) ? 1 : 0)); 
            }
        }
    
    int ans = 0;
    for(int i=0; i<h; i++)
        umax(ans, dp[n][i]);
    printf("%d\n", ans);
    
	return 0;
}
