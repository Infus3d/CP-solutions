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
 
const int N = 5e3+2;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, k;
ll dp[N][N], d[N];

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; i++){
        scanf("%lld", d+i);
        d[i] += d[i-1];
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<=k; j++){
            umax(dp[i+1][j], dp[i][j]);
            if(j < k && i+m <= n)
                umax(dp[i+m][j+1], dp[i][j] + (d[i+m] - d[i]));
        }
    
    printf("%lld\n", dp[n][k]);
    
	return 0;
}
