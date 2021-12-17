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
 
const int N = 1e3+2;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, k;
int dp[2][N<<1][4];
int c[4][4];

int main(){
    scanf("%d%d", &n, &k);
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++){
            if((i&1) ^ (j&1))
                c[i][j]++;
            if((i&2) ^ (j&2))
                c[i][j]++;
            if(c[i][j] && !((j&1) ^ ((j>>1)&1)))
                c[i][j]--;
        }
    
    for(int u=0; u<4; u++)
        dp[0][1+((u&1)^((u>>1)&1))][u] = 1; 
    for(int i=2; i<=n; i++){
        for(int j=1; j<=k; j++){
            for(int u=0; u<4; u++){
                for(int v=0; v<4; v++){
                    if(j-c[v][u] >= 0)
                        dp[1][j][u] = (dp[1][j][u] + dp[0][j-c[v][u]][v]) % MOD;
                }
            }
        }
        for(int j=0; j<=k; j++){
            for(int u=0; u<4; u++){
                dp[0][j][u] = dp[1][j][u];
                dp[1][j][u] = 0;
            }
        }
    }
    
    int ans = 0;
    for(int u=0; u<4; u++)
        ans = (ans + dp[0][k][u]) % MOD;
    printf("%d\n", ans);
    
	return 0;
}
