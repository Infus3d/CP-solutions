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
 
const int N = 1e2+2;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;
const ll INF = 1e18;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, k;
int c[N];
ll dp[N][N][N], p[N][N];

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; i++) scanf("%d", &c[i]);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%lld", &p[i][j]);
    
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            for(int v=0; v<=k; v++){
                if(dp[i-1][j][v] != -1){
                    for(int u=(!c[i] ? 1 : c[i]); u<=(!c[i] ? m : c[i]); u++){
                        if(u == j)
                            dp[i][u][v] = min(dp[i-1][j][v] + (!c[i] ? p[i][u] : 0), dp[i][u][v] == -1 ? INF : dp[i][u][v]);
                        else
                            dp[i][u][v+1] = min(dp[i-1][j][v] + (!c[i] ? p[i][u] : 0), dp[i][u][v+1] == -1 ? INF : dp[i][u][v+1]);
                    }
                }
            }
        }
    }
    
    ll ans = INF;
    for(int i=1; i<=m; i++)
        if(dp[n][i][k] != -1)
            ans = min(ans, dp[n][i][k]);
    printf("%lld\n", ans == INF ? -1LL : ans);
    
	return 0;
}
